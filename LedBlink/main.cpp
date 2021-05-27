#include <gpiod.hpp>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int main()
{
    // Iterate through the GPIO chips and print the chips
    for(auto& cit: gpiod::make_chip_iter())
    {
        std::cout << cit.name() << " - " << cit.num_lines() << " lines." << std::endl;
    }
    const std::string chipName = "gpiochip1";
    constexpr int offset = 24;
    // Get the number of lines in chip0
    gpiod::chip chip(chipName);
    auto lines = chip.get_line(offset);
    const auto direction = lines.direction();
    std::cout << "Current direction of the line(before setting) : " << direction << std::endl;
    // Try to set the direction
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Check if we are already on output, if so, then dont set it again.
    if(!(direction == GPIOD_LINE_DIRECTION_OUTPUT))
    {
        // lines.request({"debian", gpiod::line_request::DIRECTION_OUTPUT, 0});
        std::cout << "Is the user has ownership 1 : " << lines.is_requested() << std::endl;
        std::cout << "Current direction of the line(after setting) : " << lines.direction() << std::endl;
    }
    // Request for the line.
    lines.request({"debian", gpiod::line_request::DIRECTION_OUTPUT,
                   gpiod::line_request::FLAG_ACTIVE_LOW});
    std::cout << "Is the user has ownership : " << lines.is_requested() << std::endl;
    std::cout << "Current bias of the line : " << lines.bias() << std::endl;
    int value = 0;
    for(int i = 0; i < 10; i++)
    {
        lines.set_value(value);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        value = !value;
    }
    return EXIT_SUCCESS;
}
