cmake_minimum_required(VERSION 3.21)
project(algorithms C CXX)

if(NOT ALGORITHM_DIR)
    set(ALGORITHM_DIR ${CMAKE_CURRENT_LIST_DIR})
endif()

include(${ALGORITHM_DIR}/Definitions.cmake)


