#include <iostream>
#include <cmath>
#include <array>
#include <unistd.h>
#include "mycordic.hpp"

#define LUT_PRECISION 10

// LUT that holds inverse tangents of powers 2^-1
std::array<double, LUT_PRECISION> lut;

const double K = 0.6072529350088812561694;

int main()
{
    // <---------------------------->
    
    uint8_t i = 0; // <--- CORDIC iteration value

    // Populate array with values
    for(int j = 0; j < LUT_PRECISION; j++) lut[j] = atan(std::pow(2, -j));

    // print values to ensure correctness
    // for(auto each : lut) std::cout << each << std::endl;
    
    
    // 
    // 

    


    return 0;
}
