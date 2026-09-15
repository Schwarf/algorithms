cmake_minimum_required(VERSION 3.20)

project(behavioral_patterns LANGUAGES CXX)

add_executable(observer_plain observer_plain.cpp)
add_executable(observer_weak_ptr observer_weak_ptr.cpp)
add_executable(observer_callback observer_callback.cpp)

add_test(NAME observer_plain_run COMMAND observer_plain)
add_test(NAME observer_weak_ptr_run COMMAND observer_weak_ptr)
add_test(NAME observer_callback_run COMMAND observer_callback)
