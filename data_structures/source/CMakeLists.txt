cmake_minimum_required(VERSION 3.20)
project(data_structures C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)
include(CheckCXXCompilerFlag)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.71.0)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()


function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CUDA_FLAGS}" "${flag}" flag_already_set)
    if (flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if (flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif ()
        unset(flag_supported CACHE)
    endif ()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
enable_cxx_compiler_flag_if_supported("-std=c++17")
enable_cxx_compiler_flag_if_supported("-O0")

set(LIBRARY_DIRECTORIES "")

file(GLOB ALL_SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/*)


foreach (SUBDIR ${ALL_SUBDIRS})
    # Check if it is a directory but not named 'test'
    if (IS_DIRECTORY ${SUBDIR} AND NOT SUBDIR STREQUAL "test")
        # Look for .h files in the directory
        file(GLOB H_FILES_IN_SUBDIR "${SUBDIR}/*.h")
        # If .h files are found, add the .h files to a library named like the SUBDIR-name
        if (H_FILES_IN_SUBDIR)
            get_filename_component(SUBDIR_NAME ${SUBDIR} NAME)
            set(LIB_NAME "${SUBDIR_NAME}_lib")
            add_library(${LIB_NAME} INTERFACE stacks_and_queues/monotonic_stack_and_queue/stack_polish_notation.h)
            target_sources(${LIB_NAME} INTERFACE ${H_FILES_IN_SUBDIR})
        endif ()
    endif ()
endforeach ()

add_subdirectory(test)
