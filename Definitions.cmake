
# prevents processing CMake files more than once
include_guard(GLOBAL)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_DEFINITIONS ${CMAKE_CURRENT_LIST_DIR}/Definitions.cmake CACHE INTERNAL "" FORCE)

if(NOT REPO_ROOT_DIRECTORY)
    execute_process(COMMAND git rev-parse --show-toplevel OUTPUT_VARIABLE REPO_ROOT_DIRECTORY)
    file(TO_CMAKE_PATH "${REPO_ROOT_DIRECTORY}" REPO_ROOT_DIRECTORY)
    string(STRIP "${REPO_ROOT_DIRECTORY}" REPO_ROOT_DIRECTORY)
    set(REPO_ROOT_DIRECTORY ${REPO_ROOT_DIRECTORY} CACHE INTERNAL "git repo root directory")
endif()

set(BACKTRACKING_DIR ${ALGORITHM_DIR}/backtracking)
set(BINARY_SEARCH_DIR ${ALGORITHM_DIR}/binary_search)
set(BIT_MANIPULATION_DIR ${ALGORITHM_DIR}/bit_manipulation)
set(DATA_STRUCTURES_DIR, ${ALGORITHM_DIR}/data_structures)
set(DYNAMIC_PROGRAMMING_DIR, ${ALGORITHM_DIR}/dynamic_programming)
set(FUN_WITH_ALGOS_DIR, ${ALGORITHM_DIR}/fun_with_algos)
set(FUN_WITH_ARRAYS_DIR, ${ALGORITHM_DIR}/fun_with_arrays)
set(FUN_WITH_STRINGS_DIR, ${ALGORITHM_DIR}/fun_with_strings)
set(LINKED_LIST_DIR, ${ALGORITHM_DIR}/linked_lists)
set(PREFIX_SUM_DIR, ${ALGORITHM_DIR}/prefix_sum)
set(PROBABILISTIC_ALGORITHMS_DIR, ${ALGORITHM_DIR}/probabilistic_algorithms)
set(SLIDING_WINDOWS_DIR, ${ALGORITHM_DIR}/sliding_windows)
set(SORTING_ALGORITHM_DIR, ${ALGORITHM_DIR}/sorting_algorithm)
set(TEMPLATE_REMINDERS_DIR, ${ALGORITHM_DIR}/template_reminders)
