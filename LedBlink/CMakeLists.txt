set(EXENAME ledblink)
add_executable(${EXENAME} main.cpp)
# Link libraries
# For this to work, we need to link libgpiodcxx and libgpiod
unset(CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES)
unset(CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES)

# Find libraries
# We will find the C library first
find_library(GPIOD_C_LIBRARY NAMES libgpiod.so)
if(NOT GPIOD_C_LIBRARY)
    message(FATAL_ERROR "gpiod library is not found. Install it or compile it.")
endif()
# We will find the CXX library next
find_library(GPIOD_CXX_LIBRARY NAMES libgpiodcxx.so)
if(NOT GPIOD_CXX_LIBRARY)
    message(FATAL_ERROR "gpiodcxx library not found. Compile it by activating bindings.")
endif()

# Seems to be required for the libgpiod library
include_directories(${EXENAME} PRIVATE ${CMAKE_SYSROOT}/usr/local/include)
link_directories(${CMAKE_SYSROOT}/usr/local/lib)
target_link_libraries(${EXENAME} ${GPIOD_C_LIBRARY} ${GPIOD_CXX_LIBRARY})

# We could also install them on beaglebone
install(TARGETS ${EXENAME} DESTINATION exploring_beaglebone)

