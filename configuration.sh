CMAKE_OUTPUT_DIR=/var/tmp/wunderwaffe
CMAKE_SOURCE_DIR=~/workspace/wunderwaffe-c++

TOOLCHAIN_FILES="clang.cmake"
TOOLCHAIN_FILES+=" amd64.cmake"
TOOLCHAIN_FILES+=" ppc.cmake"
# TOOLCHAIN_FILES+=" mips64.cmake"
# TOOLCHAIN_FILES+=" mips64-octeon.cmake"
TOOLCHAIN_FILES+=" arm.cmake"
TOOLCHAIN_FILES+=" mingw-gcc-amd64.cmake"

GENERATOR=Ninja
