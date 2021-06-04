set(EXENAME absolute_encoder_testing)
add_executable(${EXENAME} main.cpp)

# We could also install them on beaglebone
install(TARGETS ${EXENAME} DESTINATION exploring_beaglebone)
