cmake_minimum_required(VERSION 3.20)

project(creational_patterns LANGUAGES CXX)

add_executable(factory_method factory_method.cpp)
add_executable(singleton singleton.cpp)
add_executable(builder builder.cpp)
add_executable(prototype prototype.cpp)

add_test(NAME factory_method_run COMMAND factory_method)
add_test(NAME singleton_run COMMAND singleton)
add_test(NAME builder_run COMMAND builder)
add_test(NAME prototype_run COMMAND prototype)