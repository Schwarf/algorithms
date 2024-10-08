cmake_minimum_required(VERSION 3.20)
project(data_structures C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)
include(CheckCXXCompilerFlag)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.71.0)

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
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare") # Disable specific warning

set(LIBRARY_DIRECTORIES "")

file(GLOB ALL_SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach (SUBDIR ${ALL_SUBDIRS})
    if (IS_DIRECTORY ${SUBDIR} AND NOT SUBDIR STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}/test")
        file(GLOB H_FILES_IN_SUBDIR "${SUBDIR}/*.h")
        if (H_FILES_IN_SUBDIR)
            get_filename_component(SUBDIR_NAME ${SUBDIR} NAME)
            set(LIB_NAME "${SUBDIR_NAME}_lib")
            add_library(${LIB_NAME} INTERFACE)
            target_sources(${LIB_NAME} INTERFACE ${H_FILES_IN_SUBDIR})
            list(APPEND LIBRARY_DIRECTORIES ${SUBDIR})
        endif ()
    endif ()
endforeach ()

add_subdirectory(test)
