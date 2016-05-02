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
message(STATUS "LLVM_FOUND: ${LLVM_FOUND}")
message(STATUS "LLVM_LIBRARIES: ${LLVM_LIBRARIES}")
message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_DEFINITIONS: ${LLVM_DEFINITIONS}")


###################
# Production code #
###################

include_directories(source)

add_library(state-machine-driver SHARED source/state-machine-driver.c)
add_library(state-machine        SHARED source/state-machine.c)
add_library(builder              SHARED source/build.c)
add_library(multitask            SHARED source/multitask.cpp)
add_library(llvm-pass            MODULE source/llvm-pass.cpp)

set(pure_c_libs     state-machine-driver;
                    state-machine;
                    builder;
)

set(cpp_modules     llvm-pass;
)

set(cpp_libs   multitask;
)

add_executable(${CMAKE_PROJECT_NAME}
    source/main.cpp
)

include_directories(/usr/include/qt4)
link_directories(   /usr/lib/qt4)
add_executable(     qt-app EXCLUDE_FROM_ALL source/main-qt.cpp)


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

set_target_properties(${pure_c_libs}
  PROPERTIES
  COMPILE_FLAGS -ansi
)

set_target_properties(${CMAKE_PROJECT_NAME}-test ${cpp_libs} ${cpp_modules}
  PROPERTIES
  COMPILE_FLAGS -std=c++11
)


###########
# Lilibs###########

target_link_libraries(${CMAKE_PROJECT_NAME}      ${pure_c_libs} ${cpp_libs})
target_link_libraries(${CMAKE_PROJECT_NAME}-test ${pure_c_libs} ${cpp_libs} CppUTest CppUTestExt)

target_link_libraries(qt-app                     QtGui QtCore)
# target_link_libraries(llvm-pass                  ${LLVM_LIBRARIES} LLVMCore)


#####################
# Auxiliary targets #
#####################

add_custom_target(run-test
    COMMAND cp ${CMAKE_SOURCE_DIR}/source-test/llvm-pass-example.cpp ${CMAKE_BINARY_DIR}/
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}-test
    DEPENDS ${CMAKE_PROJECT_NAME}-test ${cpp_modules}
    COMMENT "${to_host_translator} ./${CMAKE_PROJECT_NAME}-test"
)

add_custom_target(run
    COMMAND ${to_host_translator} ./${CMAKE_PROJECT_NAME}
    DEPENDS ${CMAKE_PROJECT_NAME} ${cpp_modules}
    COMMENT "${to_host_translator} ./${CMAKE_PROJECT_NAME}"
)

add_custom_target(run-qt
    COMMAND qt-app
    DEPENDS ${cpp_modules}
)
