#include <iostream>
#include <cmath>
#include <array>
#include <unistd.h>
#include "mycordic.hpp"

// CORDIC approximation algorithm to be tested
// against the  built in C++ library algorithm



int main()
{
    mycordic::populate_lut();

    // print values to ensure correctness
    for(auto each : mycordic::lut) std::cout << each << std::endl;
    
    
    // mycordic::calc_cordic();
    

    


    return 0;
}
