#include "mycircularbuffer.hpp"

// My implementation of a circular
// buffer. It will most likely be
// used for DSP related algorithms

int main()
{
    // Create Circular buffer object
    mycircularbuffer<double> buff_1;
    std::cout << "The Vector size is : " << buff_1.vectr_size() << std::endl;
    buff_1.insert_end(34.75);
    buff_1.insert_end(44.12);
    buff_1.insert_end(112.776);
    std::cout << "The new Vector size is : " << buff_1.vectr_size() << std::endl;
    std::cout << "The value at inde 0 is : " << buff_1.get_at(0) << std::endl;
    std::cout << "The value at inde 1 is : " << buff_1.get_at(1) << std::endl;
    std::cout << "The value at inde 2 is : " << buff_1.get_at(2) << std::endl;
    std::cout << "The value at inde 666 is : " << buff_1.get_at(666) << std::endl;
    std::cout << "Program Done!" << std::endl;
    return 0;
}
