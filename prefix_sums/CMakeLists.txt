cmake_minimum_required(VERSION 3.20)
project(prefix_sums C CXX)

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
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-Wno-sign-compare") # Disable specific warning




file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
set(LIB_NAME "prefix_sums_lib")
add_library(${LIB_NAME} INTERFACE
        number_of_subarrays.h
        make_divisible_by_value.h)
target_sources(${LIB_NAME} INTERFACE ${HEADER_FILES})

add_subdirectory(test)
