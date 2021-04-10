# Set the system name
set(CMAKE_SYSTEM_NAME Linux)
# C Compiler
set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)
# Sysroot location
# It is mounted using sshfs
set(CMAKE_SYSROOT /home/kalyan/Beaglebone-Sysroot)
# These lines are necessary to let cmake know to only look in the
# beaglebone for the libraries instead of looking in host pc.
# sshfs debian@192.168.7.2:/ /home/kalyan/Beaglegone-Sysroot/ -o transform_symlinks
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

