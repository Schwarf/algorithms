
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
