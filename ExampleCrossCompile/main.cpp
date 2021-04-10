#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <gpiod.hpp>

using namespace std;

int main(int argc, char** argv)
{
    cout << "Hello World!" << endl;
    if(argc!= 1)
    {
        std::cerr << "Usage : " << argv[0] << std::endl;
    }
    for (auto& cit: gpiod::make_chip_iter())
    {
        std::cout << cit.name() << " - " << cit.num_lines() << " lines" << std::endl;
    }
    return 0;
}
