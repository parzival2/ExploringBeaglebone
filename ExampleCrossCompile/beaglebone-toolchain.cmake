# compiler
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)
# sysroot location
set(CMAKE_SYSROOT /home/kalyan/Beaglebone-Sysroot)
message(STATUS "CMAKE_SYSROOT in Toolchain : " ${CMAKE_SYSROOT})
# set(CMAKE_PREFIX_PATH ${CMAKE_SYSROOT})
# set(CMAKE_FIND_ROOT_PATH ${CMAKE_SYSROOT})
# compiler/linker flags
# cmake built-in settings to use find_xxx() functions
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# SET(ENV{PKG_CONFIG_LIBDIR} ${CMAKE_SYSROOT}/usr/local/lib/pkgconfig)
# SET(ENV{PKG_CONFIG_SYSROOT_DIR} ${CMAKE_SYSROOT})
