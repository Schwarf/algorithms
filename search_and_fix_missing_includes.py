from pathlib import Path
import re

TARGET_EXTENSIONS = {".h", ".cpp"}

ALGORITHM_SYMBOLS = [
    "std::sort",
    "std::reverse",
    "std::max_element",
    "std::min_element",
    "std::max",
    "std::min",
]

ALGORITHM_INCLUDE = "#include <algorithm>"

PRAGMA_ONCE_RE = re.compile(r"^\s*#pragma\s+once\s*$")
INCLUDE_RE = re.compile(r"^\s*#include\s*[<\"].*[>\"]\s*$")


def file_needs_algorithm_include(content: str) -> bool:
    uses_algorithm_symbol = any(symbol in content for symbol in ALGORITHM_SYMBOLS)
    has_algorithm_include = ALGORITHM_INCLUDE in content
    return uses_algorithm_symbol and not has_algorithm_include


def insert_algorithm_include(content: str) -> str:
    lines = content.splitlines(keepends=True)

    # 1. Insert after #pragma once if present
    for i, line in enumerate(lines):
        if PRAGMA_ONCE_RE.match(line):
            insert_at = i + 1
            # avoid double blank-line growth
            if insert_at < len(lines) and lines[insert_at].strip() == "":
                return "".join(lines[:insert_at] + [ALGORITHM_INCLUDE + "\n"] + lines[insert_at:])
            return "".join(lines[:insert_at] + [ALGORITHM_INCLUDE + "\n"] + lines[insert_at:])

    # 2. Otherwise insert after the last contiguous include line near the top
    last_include_idx = None
    for i, line in enumerate(lines):
        stripped = line.strip()

        if INCLUDE_RE.match(line):
            last_include_idx = i
            continue

        # allow blank lines inside the include block
        if stripped == "" and last_include_idx is not None:
            continue

        # stop scanning once real code or something else begins
        if last_include_idx is not None:
            break

        # if we haven't seen includes yet, keep scanning a little further
        # comments/header guards will fall through and be handled below

    if last_include_idx is not None:
        insert_at = last_include_idx + 1
        return "".join(lines[:insert_at] + [ALGORITHM_INCLUDE + "\n"] + lines[insert_at:])

    # 3. Fallback: insert at top
    return ALGORITHM_INCLUDE + "\n" + content


def process_file(path: Path) -> bool:
    try:
        content = path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        try:
            content = path.read_text(encoding="latin-1")
        except Exception:
            return False
    except Exception:
        return False

    if not file_needs_algorithm_include(content):
        return False

    new_content = insert_algorithm_include(content)

    if new_content != content:
        path.write_text(new_content, encoding="utf-8")
        return True

    return False


def main(root: str = ".") -> None:
    changed_files = []

    for path in Path(root).rglob("*"):
        if not path.is_file():
            continue
        if path.suffix not in TARGET_EXTENSIONS:
            continue

        if process_file(path):
            changed_files.append(str(path))

    print("Modified files:")
    for file in changed_files:
        print(file)

    print(f"\nTotal modified: {len(changed_files)}")


if __name__ == "__main__":
    main(".")