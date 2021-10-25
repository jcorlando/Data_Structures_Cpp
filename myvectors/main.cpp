#include <iostream>
#include "myvectors.hpp"
#include "eigenlibvectors.hpp"


int main()
{
    myvector<double, 2> vectr2d_a;
    myvector<double, 2> vectr2d_b( {1.1, 2.2} );
    myvector<double, 3> vectr2d_c( {1.1, 2.2, 3.3} );

    std::cout << "out of bounds check for vectr2d_a : " << vectr2d_a[2] << std::endl;
    std::cout << "out of bounds check for vectr2d_b : " << vectr2d_b[2] << std::endl;
    std::cout << "out of bounds check for vectr2d_c : " << vectr2d_c[2] << std::endl;


    return 0;
}
