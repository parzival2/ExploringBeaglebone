#include <iostream>
#include <stdint.h>
#include <bitset>
#include <sstream>
#include <iomanip>

std::string display(uint8_t a)
{
    std::stringstream ss;
    ss << std::setw(3) << (int)a << "(" << std::bitset<8>(a) << ")";
    return ss.str();
}

int main()
{
    uint8_t a = 25;
    uint8_t b = 5;
    std::cout << "A = " << display(a) << "\nB = " << display(b) << std::endl;
    std::cout << "A & B (AND) = " << display(a & b) << std::endl;
    std::cout << "A | B (OR) = " << display(a | b) << std::endl;
    std::cout << "~A (NOT) = " << display(~a) << std::endl;
    std::cout << "A ^ B (XOR) = " << display(a ^ b) << std::endl;
    std::cout << "A << 1 (LSL) = " << display(a << 1) << std::endl;
    std::cout << "A >> 1 (LSR) = " << display(a >> 1) << std::endl;
    std::cout << "1 << 8 (LSL) = " << display(1 << 7) << std::endl;
    return 0;
}
