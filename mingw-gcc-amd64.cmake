# State of research:
# Mingw could make bosse compilation possible on Linux (target would run on Windows/Wine/etc...) 
# but bosse pulls dependencies to MFC which is hard (=impossible?) to build on Linux
# BUT if e.g. QT replaced MFC in Bosse (scheduler), than it should be possible.
# Question: is it worth? Maybe Bosse will die earlier.



##### pragma once #####
if(mingw_toolchain_cmake_included)
    return()
endif()
set(mingw_toolchain_cmake_included true)
#######################


include(CMakeForceCompiler)

# File that sets up the OAM build toolchain.
# Pass it to the cmake with the -DCMAKE_TOOLCHAIN_FILE option

# Supported options: Linux, Windows, OSE
set(CMAKE_SYSTEM_NAME 					Windows)
set(CMAKE_SYSTEM_PROCESSOR 				x86_64)
set(BUILD_SHARED_LIBS                   false)

# This is used in Definitions.cmake files
#set(CMAKE_COMPILER 						gcc)

cmake_force_c_compiler(mingw32-gcc 		GNU)
cmake_force_cxx_compiler(mingw32-g++ 	GNU)
#cmake_c_compiler(mingw32-gcc GNU)
#cmake_cxx_compiler(mingw32-gcc GNU)

# which compilers to use for C and C++
#find_program(CMAKE_RC_COMPILER NAMES ${COMPILER_PREFIX}-windres)
#SET(CMAKE_RC_COMPILER ${COMPILER_PREFIX}-windres)

SET(CMAKE_FIND_ROOT_PATH  				/usr/mingw32/usr)
include_directories(                    ${CMAKE_FIND_ROOT_PATH}/include)

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search 
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM 	NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY	ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE 	ONLY)

execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE COMPILER_VERSION)
string(STRIP ${COMPILER_VERSION} COMPILER_VERSION)

set(to_host_translator      wine)