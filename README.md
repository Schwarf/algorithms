# Algorithms

A personal C++ repository for learning, practicing, and experimenting with algorithms and data structures.

This repository has grown over time while solving problems, trying out data-structure implementations, and exploring different algorithmic techniques. It is primarily a learning repository rather than a polished library.

## Purpose

The main goals of this repository are:

- practice algorithms and data structures in C++
- explore different solution ideas and implementation styles
- collect reusable reference implementations
- learn testing, benchmarking, and build tooling around small algorithmic projects

## What is in the repo

The repository contains a mix of:

- classic data structures such as trees, heaps, tries, linked lists, graphs, stacks, queues, union-find variants, and caches
- algorithmic problem solutions across topics such as:
    - backtracking
    - binary search
    - bit manipulation
    - dynamic programming
    - greedy / interval-style problems
    - prefix sums
    - sliding window
    - sorting
    - string problems
    - probabilistic algorithms
- unit tests for many implementations
- some benchmarking and profiling code

The code base is organized by topic rather than as a single library.

## Status

This is a learning repository, so the code base is intentionally broad and not fully uniform.

In particular:

- not all code follows fully modern production-quality standards
- naming, structure, and implementation style are not completely consistent across the repository
- some parts are older and reflect earlier learning stages
- test coverage is useful, but incomplete
- test cases do not necessarily cover every edge case

So while many implementations can be useful as references, this repository should not be treated as a production-ready algorithms framework.

## Build environment

The repository provides a **devcontainer based on Ubuntu 24.04 LTS**.

The current setup supports:

- **GCC 13** in Debug and Release
- **Clang 18** in Debug and Release

The repository currently defines CMake presets for:

- `gcc-debug`
- `gcc-release`
- `clang-debug`
- `clang-release`

and matching build and test presets.

## Quick start

### GCC Debug
```bash
cmake --preset gcc-debug
cmake --build --preset gcc-debug -j
ctest --preset all-gcc-debug --output-on-failure
```

### GCC Release
```bash
cmake --preset gcc-release
cmake --build --preset gcc-release -j
ctest --preset all-gcc-release --output-on-failure
```

### Clang Debug
```bash
cmake --preset clang-debug
cmake --build --preset clang-debug -j
ctest --preset all-clang-debug --output-on-failure
```

### Clang Release
```bash
cmake --preset clang-release
cmake --build --preset clang-release -j
ctest --preset all-clang-release --output-on-failure
```
