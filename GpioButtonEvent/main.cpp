#include <gpiod.hpp>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int main()
{
    const std::string chipName = "gpiochip1";
    constexpr int offset = 28;
    // Get the number of lines in chip0
    gpiod::chip chip(chipName);
    auto lines = chip.get_line(offset);
    const auto direction = lines.direction();
    std::cout << "Current direction of the line(before setting) : " << direction << std::endl;
    if(!(direction == GPIOD_LINE_DIRECTION_INPUT))
    {
        std::cout << "Direction of the line is not input." << std::endl;
    }
    // Try to change the direction of the line.
    lines.request({"debian", gpiod::line_request::EVENT_FALLING_EDGE,
                   0});
    std::cout << "Is the user has ownership : " << lines.is_requested() << std::endl;
    std::cout << "Current direction of the pin : " << lines.direction() << std::endl;
    for(;;)
    {
        auto events = lines.event_wait(std::chrono::seconds(1));
        if(events)
        {
            const auto event = lines.event_read();
            std::cout << "Event occured - ";
            if(event.event_type == gpiod::line_event::RISING_EDGE)
            {
                std::cout << "RISING EDGE" << std::endl;
            }
            else if(event.event_type == gpiod::line_event::FALLING_EDGE)
            {
                std::cout << "FALLING EDGE" << std::endl;
            }
        }

    }
    return 0;
}
