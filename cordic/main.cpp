#include <cmath>
#include <array>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "mycordic.hpp"

// CORDIC approximation algorithm to be tested
// against the  built in C++ library algorithm

int main()
{
    mycordic::populate_lut();

    double test_angle = 0.0;

    std::ofstream myfile;
    myfile.open("output.dat");

    for (unsigned int i = 0; i < 1081; i++)
    {
        mycordic::calc_cordic(test_angle, myfile);

        test_angle = test_angle + 0.333333333333333333333333333333333333333333333333333333333333333333333333333333333333;
    }

    
    myfile.close();
    
    return 0;
}
