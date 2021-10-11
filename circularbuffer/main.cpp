#include "mycircularbuffer.hpp"

// My implementation of a circular
// buffer. It will most likely be
// used for DSP related algorithms

int main()
{
    // Create Circular buffer object
    mycircularbuffer<double, 900> buff_1;
    std::cout << "The Array size is : " << buff_1.array_size() << std::endl;

    

    std::cout << "Program Done!" << std::endl;
    return 0;
}
