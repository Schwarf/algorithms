cmake_minimum_required(VERSION 3.20)

project(behavioral_patterns LANGUAGES CXX)

add_executable(observer_plain observer_plain.cpp)

add_test(NAME observer_plain_run COMMAND observer_plain)
