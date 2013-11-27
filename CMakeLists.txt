cmake_minimum_required(VERSION 2.8)
project(${CMAKE_SOURCE_DIR})

set(CMAKE_BUILD_TYPE Debug)

add_executable(${CMAKE_PROJECT_NAME} source/main.cpp)

add_custom_target(run-tests
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
)