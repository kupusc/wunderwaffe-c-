############
# Preamble #
############

cmake_minimum_required(VERSION 2.8)
project(${PROJECT_NAME})


#################
# Main settings #
#################

set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
set(CMAKE_USE_RELATIVE_PATHS ON CACHE BOOL "" FORCE)
set(C++11 ON)
set(CPPUTEST_ROOT /home/skoblins/workspace/cxx/cpputest)


##################
# test framework #
##################

add_subdirectory(${CPPUTEST_ROOT} ${CMAKE_CURRENT_BINARY_DIR}/cpputest)


#########################
# Code inspection tools #
#########################

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})


###################
# Production code #
###################

include_directories(source)

add_library(state-machine-driver SHARED source/state-machine-driver.c)
add_library(state-machine        SHARED source/state-machine.c)
add_library(builder              SHARED source/build.c)
add_library(llvm-pass            SHARED source/llvm-pass.cpp)

set(libs    state-machine-driver;
            state-machine;
            builder;
            llvm-pass
)

set(modules llvm-pass)

add_executable(${CMAKE_PROJECT_NAME}
    source/main.cpp
)

include_directories(/usr/include/qt4)
link_directories(/usr/lib/qt4)
add_executable(qt-app EXCLUDE_FROM_ALL source/main-qt.cpp)


#########
# Tests #
#########

include_directories(${CPPUTEST_ROOT}/include)

add_executable(${CMAKE_PROJECT_NAME}-test
    source-test/main.cpp
    source-test/state-machine-driver.cpp
    source-test/state-machine.cpp
    source-test/free-tests.cpp
    source-test/llvm-pass.cpp
)


#########################
# Production PROPERTIES #
#########################

set_target_properties(${libs}
  PROPERTIES
  COMPILE_FLAGS -ansi
)

set_target_properties(${CMAKE_PROJECT_NAME}-test ${modules}
  PROPERTIES
  COMPILE_FLAGS -std=c++11
)


###########
# Linking #
###########

target_link_libraries(${CMAKE_PROJECT_NAME}      ${libs})
target_link_libraries(${CMAKE_PROJECT_NAME}-test ${libs} CppUTest CppUTestExt)

target_link_libraries(qt-app                     QtGui QtCore)


#####################
# Auxiliary targets #
#####################

add_custom_target(run-test
    COMMAND cp ${CMAKE_SOURCE_DIR}/source-test/llvm-pass-example.cpp ${CMAKE_BINARY_DIR}/
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}-test
    DEPENDS ${CMAKE_PROJECT_NAME}-test llvm-pass
    COMMENT "${to_host_translator} ./${CMAKE_PROJECT_NAME}-test"
)

add_custom_target(run
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME} llvm-pass
    COMMENT "${to_host_translator} ./${CMAKE_PROJECT_NAME}"
)

add_custom_target(run-qt
    COMMAND qt-app
    DEPENDS llvm-pass
)
