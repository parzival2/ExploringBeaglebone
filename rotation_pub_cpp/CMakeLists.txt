# Add Executable
add_executable(rotation_pub_cpp main.cpp)
target_link_libraries(rotation_pub_cpp zcm)
# We could also install them on beaglebone
install(TARGETS rotation_pub_cpp DESTINATION exploring_beaglebone)