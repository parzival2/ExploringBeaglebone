#include <iostream>
#include <gpiod.hpp>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    // Go through the file list and print the chips found on the target.
    for(auto& cit: gpiod::make_chip_iter())
    {
        std::cout << cit.name() << " - " << cit.num_lines() << " lines." << std::endl;
    }
    return 0;
}
