cmake_minimum_required(VERSION 3.13)
project(window VERSION 1.0)
add_executable(window main.cpp)

# adder use logic
option(USE_ADDER "addition of floats/integers." ON)
if(USE_ADDER)
    add_subdirectory(../deps/adder deps/adder)
    list(APPEND EXTRA_INCLUDES ../deps/adder)
    list(APPEND EXTRA_LIBS deps/adder)
    list(APPEND EXTRA_LINKS customadder)
endif()

configure_file(window-config.h.in window-config.h)



target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

if(APPLE)
    # Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
    target_link_directories(window PRIVATE /usr/local/lib)
endif()

add_subdirectory(../deps/glfw deps/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ../deps/glfw/include
    ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME}
    PUBLIC deps/glfw/src
    ${EXTRA_LIBS}
)

target_link_libraries(${PROJECT_NAME} 
    glfw
    ${EXTRA_LINKS}
)

install(TARGETS window DESTINATION bin) 