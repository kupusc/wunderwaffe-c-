include(CMakeForceCompiler)

set(toolchain_prefix        powerpc-unknown-linux-gnu)
cmake_force_c_compiler      (${toolchain_prefix}-gcc GNU)
cmake_force_cxx_compiler    (${toolchain_prefix}-g++ GNU)

set(CMAKE_AR                ${toolchain_prefix}-ar CACHE STRING "")
set(CMAKE_AS                ${toolchain_prefix}-as CACHE STRING "")
set(CMAKE_LINKER            ${toolchain_prefix}-ld CACHE STRING "")
set(CMAKE_NM                ${toolchain_prefix}-nm CACHE STRING "")
set(CMAKE_OBJCOPY           ${toolchain_prefix}-objcopy CACHE STRING "")
set(CMAKE_OBJDUMP           ${toolchain_prefix}-objdump CACHE STRING "")
set(CMAKE_RANLIB            ${toolchain_prefix}-ranlib CACHE STRING "")


set(to_host_translator      LD_LIBRARY_PATH=/usr/lib64/gcc/${toolchain_prefix}/4.8.2 qemu-ppc -L /usr/${toolchain_prefix})

set(sysroot                 /usr/${toolchain_prefix})

foreach(flag CMAKE_EXE_LINKER_FLAGS CMAKE_EXE_LINKER_FLAGS_DEBUG CMAKE_EXE_LINKER_FLAGS_MINSIZEREL CMAKE_EXE_LINKER_FLAGS_RELEASE CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO CMAKE_MODULE_LINKER_FLAGS CMAKE_MODULE_LINKER_FLAGS_DEBUG CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL CMAKE_MODULE_LINKER_FLAGS_RELEASE CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO CMAKE_SHARED_LINKER_FLAGS CMAKE_SHARED_LINKER_FLAGS_DEBUG CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL CMAKE_SHARED_LINKER_FLAGS_RELEASE CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO)
    set(${flag} "--sysroot=${sysroot}" CACHE STRING "")
endforeach()

link_directories(/usr/lib64/gcc/${toolchain_prefix}/4.7.2/)