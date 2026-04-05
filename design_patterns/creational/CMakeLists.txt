cmake_minimum_required(VERSION 3.20)

project(factory_method LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(factory_method factory_method.cpp)
add_executable(singleton singleton.cpp)
add_executable(builder builder.cpp)