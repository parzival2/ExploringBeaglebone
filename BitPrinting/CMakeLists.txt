set(EXENAME bit_printing)
add_executable(${EXENAME} main.cpp)

# For this to work, we need to link libgpiodcxx and libgpiod
unset(CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES)
unset(CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES)

link_directories(${CMAKE_SYSROOT}/usr/local/lib)
include_directories(${EXENAME} PRIVATE ${CMAKE_SYSROOT}/usr/local/include)

# We could also install them on beaglebone
install(TARGETS ${EXENAME} DESTINATION bin)

