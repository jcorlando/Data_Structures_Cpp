#include <iostream>
#include <cmath>
#include <array>
#include <unistd.h>
#include "mycordic.hpp"

#define CORDIC_PRECISION 10

int main()
{
    // <---------------------------->
    
    uint8_t iter = 0; // iteration value

    // LUT that holds inverse tangents of powers 2^-1
    std::array<double, CORDIC_PRECISION> array;

    for(int i = 0; i < 10; i++) std::cout << atan(std::pow(2, -i)) << std::endl;


    return 0;
}
