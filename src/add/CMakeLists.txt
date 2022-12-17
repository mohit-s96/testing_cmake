cmake_minimum_required(VERSION 3.13)
project(add)
add_executable(add main.cpp)
if(APPLE)
    # Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
    target_link_directories(add PRIVATE /usr/local/lib)
ENDIF()
target_link_libraries(add customadder)
install(TARGETS add DESTINATION bin) 