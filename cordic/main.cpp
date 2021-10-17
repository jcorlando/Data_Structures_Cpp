#include <iostream>
#include <cmath>
#include <array>
#include <unistd.h>
#include "mycordic.hpp"

// CORDIC approximation algorithm to be tested
// against the  built in C++ library algorithm

// Change this to create a more precise algortihm
#define LUT_PRECISION 20

// angle to calculate SIN or COS of
double angle = 30.0;

// LUT that holds inverse tangents of powers 2^-1
std::array<double, LUT_PRECISION> lut;

// scaling factor for x and y coordinates
const double K = 0.6072529350088812561694;


int main()
{
    // Populate array with values !!!! Multiply by *(180/M_PI) to convert to degrees
    for(int i = 0; i < LUT_PRECISION; i++) lut[i] = atan(std::pow(2, -i))*(180/M_PI);

    // print values to ensure correctness
    // for(auto each : lut) std::cout << each << std::endl;
    
    
    for(auto each : lut)
    {
        if(angle >= 0)
        {
            std::cout << angle << " - " << each << " = ";
            angle = angle - each;
            std::cout << angle << std::endl;
        }
        else
        {
            std::cout << angle << " + " << each << " = ";
            angle = angle + each;
            std::cout << angle << std::endl;
        }
    }
    

    


    return 0;
}
