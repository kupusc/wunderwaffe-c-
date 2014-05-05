cmake_minimum_required(VERSION 2.8)
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

set(C++11 ON)
add_subdirectory(/home/skoblins/workspace/cpputest ${CMAKE_CURRENT_BINARY_DIR}/cpputest)
include_directories(/home/skoblins/workspace/cpputest/include
    source
)

add_library(state-machine-driver SHARED source/state-machine-driver.c)
add_library(state-machine        SHARED source/state-machine.c)

set(libs    state-machine-driver;
            state-machine)

add_executable(${CMAKE_PROJECT_NAME} 
    source/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME}-test 
    source-test/main.cpp
    source-test/state-machine-driver.cpp
    source-test/state-machine.cpp
)

set_target_properties(${libs}
  PROPERTIES
  COMPILE_FLAGS -ansi
)

set_target_properties(${CMAKE_PROJECT_NAME}-test
  PROPERTIES
  COMPILE_FLAGS -std=c++11
)

target_link_libraries(${CMAKE_PROJECT_NAME}      ${libs})
target_link_libraries(${CMAKE_PROJECT_NAME}-test ${libs} CppUTest CppUTestExt)

add_custom_target(run-test
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}-test
    DEPENDS ${CMAKE_PROJECT_NAME}-test
)

add_custom_target(run
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
)
