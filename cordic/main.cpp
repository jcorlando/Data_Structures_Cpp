#include <cmath>
#include <array>
#include <unistd.h>
#include <iostream>
#include "mycordic.hpp"

// CORDIC approximation algorithm to be tested
// against the  built in C++ library algorithm

int main()
{
    mycordic::populate_lut();

    double test_angle = 0.0;

    for (unsigned int i = 0; i < 1081; i++)
    {
        mycordic::calc_cordic(test_angle);
        test_angle = test_angle + 0.333333333333333333333333333333333333333333333333333333333333333333333333333333333333;
    }
    
    
    
    

    


    return 0;
}
