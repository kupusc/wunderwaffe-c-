PROJECT_NAME=wunderwaffe-c++

CMAKE_OUTPUT_DIR=/var/tmp/${PROJECT_NAME}
CMAKE_SOURCE_DIR=~/workspace/${PROJECT_NAME}

TOOLCHAIN_FILES="clang.cmake"
TOOLCHAIN_FILES+=" amd64.cmake"
TOOLCHAIN_FILES+=" ppc.cmake"
TOOLCHAIN_FILES+=" mips64.cmake"
# TOOLCHAIN_FILES+=" mips64-octeon.cmake"
TOOLCHAIN_FILES+=" arm.cmake"
TOOLCHAIN_FILES+=" mingw-gcc-amd64.cmake"

GENERATOR=Ninja
