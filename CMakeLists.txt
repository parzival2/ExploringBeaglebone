cmake_minimum_required(VERSION 3.0.0)
project(ExploringBeaglebone VERSION 0.1.0)
# Set CMAKE standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Print a message indicating the toolchain file
message(STATUS "Toolchain file : " ${CMAKE_TOOLCHAIN_FILE})
# Print a message indicating the SYSROOT
message(STATUS "CMAKE_SYSROOT set : " ${CMAKE_SYSROOT})
# Print the Compiler too
message(STATUS "Given CXX compiler : " ${CMAKE_CXX_COMPILER})
# Set the CMAKE install prefix. This is needed if we want to send the 
# executables and run them on beaglebone
set(CMAKE_INSTALL_PREFIX "/home/debian/ExploringBeaglebone")
# Add all the other examples
add_subdirectory(LibGpiodChipPrint)