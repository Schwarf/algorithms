cmake_minimum_required(VERSION 3.21)
project(algorithms LANGUAGES CXX)

# Language standard (let CMake add the right -std flag)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Toggle to make warnings fatal (use in Debug / CI only)
option(ALG_WERROR "Treat warnings as errors" OFF)

# Global warnings (propagate to all targets in subdirs)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-sign-compare)
    # Make warnings fatal only when the option is ON
    add_compile_options($<$<BOOL:${ALG_WERROR}>:-Werror>)

    # GCC 13 can be noisy with -Warray-bounds in heavy O3 code paths.
    # Keep Debug strict, relax Release only (optional; remove if you prefer).
    add_compile_options($<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:Release>>:-Wno-array-bounds>)
elseif (MSVC)
    add_compile_options(/W4 $<$<BOOL:${ALG_WERROR}>:/WX>)
endif()

# Testing
include(CTest)
enable_testing()

add_subdirectory(backtracking)
add_subdirectory(binary_search)
add_subdirectory(bit_manipulation)
# add_subdirectory(CTCI)
add_subdirectory(data_structures/source)
add_subdirectory(dynamic_programming)
add_subdirectory(fun_with_algos)
add_subdirectory(fun_with_strings)
add_subdirectory(prefix_sums)
add_subdirectory(probabilistic_algorithms)
add_subdirectory(sliding_window)
add_subdirectory(sorting_algorithms)
add_subdirectory(template_reminders)
