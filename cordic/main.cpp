#include <iostream>
#include <cmath>
#include <array>
#include <unistd.h>
#include "mycordic.hpp"

#define LUT_PRECISION 10

// LUT that holds inverse tangents of powers 2^-1
std::array<double, LUT_PRECISION> lut;

int main()
{
    // <---------------------------->
    
    uint8_t iter = 0; // iteration value

    for(int i = 0; i < LUT_PRECISION; i++) lut[i] = atan(std::pow(2, -i));

    for(auto each : lut) std::cout << each << std::endl;
    


    return 0;
}
