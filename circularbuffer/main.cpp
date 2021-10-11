#include <iostream>

#include "mycircularbuffer.hpp"

// My implementation of a circular
// buffer. It will most likely be
// used for DSP related algorithms

int main()
{
    // Create Circular buffer object
    mycircularbuffer<double, 5> buff_1;
    std::cout << "The Array size is : " << buff_1.array_size() << std::endl;

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Inserting Now..." << std::endl;

    buff_1.insert(1.111);

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Inserting Now..." << std::endl;

    buff_1.insert(2.222);

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Inserting Now..." << std::endl;

    buff_1.insert(3.333);

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Inserting Now..." << std::endl;

    buff_1.insert(4.444);

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Inserting Now..." << std::endl;

    buff_1.insert(5.555);

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Inserting Now..." << std::endl;

    buff_1.insert(6.666);

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    std::cout << "Program Done!" << std::endl;
    return 0;
}
