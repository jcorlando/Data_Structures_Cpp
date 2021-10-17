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
    
    mycordic::calc_cordic(30.0);
    

    


    return 0;
}
