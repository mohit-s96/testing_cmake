cmake_minimum_required(VERSION 2.8)
project(customadder)
add_library(customadder adder.cpp)
set_target_properties(customadder PROPERTIES PUBLIC_HEADER adder.h)
install(TARGETS customadder DESTINATION lib
       PUBLIC_HEADER DESTINATION include 
)