cmake_minimum_required(VERSION 3.0.0)
project(ExploringBeaglebone VERSION 0.1.0)
# Set CMAKE standard
SET(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# Print a message indicating the toolchain file
message(STATUS "Toolchain file : " ${CMAKE_TOOLCHAIN_FILE})
# Print a message indicating the SYSROOT
message(STATUS "CMAKE_SYSROOT set : " ${CMAKE_SYSROOT})
# Print the Compiler too
message(STATUS "Given CXX compiler : " ${CMAKE_CXX_COMPILER})
# Set the CMAKE install prefix. This is needed if we want to send the 
# executables and run them on beaglebone
# set(CMAKE_INSTALL_PREFIX "/home/root/ExploringBeaglebone")
# Add all the other examples
add_subdirectory(LibGpiodChipPrint/)
add_subdirectory(LedBlink/)
add_subdirectory(GpioButtonEvent/)
add_subdirectory(BitPrinting/)
add_subdirectory(AS5600_Testing/)
add_subdirectory(rotation_pub_cpp/)
