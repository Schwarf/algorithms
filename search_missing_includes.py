import os
from pathlib import Path

def find_files_missing_algorithm_include(root: str = ".") -> list[str]:
    missing = []

    for path in Path(root).rglob("*"):
        if not path.is_file():
            continue
        if path.suffix not in {".h", ".cpp"}:
            continue

        try:
            content = path.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            try:
                content = path.read_text(encoding="latin-1")
            except Exception:
                continue
        except Exception:
            continue

        uses_sort_or_reverse = ("std::sort" in content) or ("std::reverse" in content) or ("std::max_element" in content)
        has_algorithm_include = "#include <algorithm>" in content

        if uses_sort_or_reverse and not has_algorithm_include:
            missing.append(str(path))

    return sorted(missing)


if __name__ == "__main__":
    result = find_files_missing_algorithm_include(".")

    print("Files using std::sort or std::reverse without #include <algorithm>:")
    for file in result:
        print(file)

    print(f"\nTotal: {len(result)}")