cmake_minimum_required(VERSION 2.8)
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)
# set(BUILD_SHARED_LIBS true)

add_library(state-machine
    source/state-machine.c
)

add_executable(${CMAKE_PROJECT_NAME} 
    source/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME}-test 
    source-test/main.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} 
    state-machine
)

target_link_libraries(${CMAKE_PROJECT_NAME}-test 
    state-machine
)

add_custom_target(run-test
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}-test
    DEPENDS ${CMAKE_PROJECT_NAME}
)

add_custom_target(run
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME}
)

# add_definitions(--address-sanitizer)