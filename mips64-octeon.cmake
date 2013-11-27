include(CMakeForceCompiler)

cmake_force_c_compiler      (mips64-octeon-linux-gnu-gcc GNU)
cmake_force_cxx_compiler    (mips64-octeon-linux-gnu-g++ GNU)
set(CMAKE_AS                mips64-octeon-linux-gnu-as CACHE STRING "")