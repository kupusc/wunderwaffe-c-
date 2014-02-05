cmake_minimum_required(VERSION 2.8)
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(/home/skoblins/workspace/cpputest ${CMAKE_CURRENT_BINARY_DIR}/cpputest)
include_directories(/home/skoblins/workspace/cpputest/include
    source
)

add_library(state-machine-driver
    source/state-machine-driver.c
)

add_executable(${CMAKE_PROJECT_NAME} 
    source/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME}-test 
    source-test/main.cpp
    source-test/state-machine-driver.cpp
    source-test/state-machine.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} 
    state-machine-driver
)

target_link_libraries(${CMAKE_PROJECT_NAME}-test 
    state-machine-driver
    CppUTest
    CppUTestExt
)

add_custom_target(run-test
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}-test
    DEPENDS ${CMAKE_PROJECT_NAME}-test
)

add_custom_target(run
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
)

# add_definitions(--address-sanitizer)