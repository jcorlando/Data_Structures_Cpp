#include <cmath>
#include <array>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include "mycordic.hpp"

// CORDIC approximation algorithm to be tested
// against the  built in C++ library algorithm

int main()
{
    mycordic::populate_lut();


    // <----------Start Timer---------->
    auto start = std::chrono::high_resolution_clock::now();
    // <----------Start Timer---------->

    double test = std::cos( 180 * (M_PI/180) );
    // mycordic::calc_cordic(0);

    // <-----------End Timer----------->
    auto stop = std::chrono::high_resolution_clock::now();
    // <-----------End Timer----------->

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    
    return 0;
}
