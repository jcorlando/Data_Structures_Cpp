#include <iostream>

#include "mycircularbuffer.hpp"

// My implementation of a circular
// buffer. It will most likely be
// used for DSP related algorithms



// Below are different testing functions
void insert_func(mycircularbuffer<double, 5> &object, double value)
{
    std::cout << "Inserting Now..." << std::endl;

    object.insert(value);

    std::cout << "The Front is at : " << object.get_front() << std::endl;

    std::cout << "The Back is at : " << object.get_back() << std::endl;

    std::cout << "The current length is : " << object.get_length() << std::endl << std::endl;
}





int main()
{
    // Create Circular buffer object
    mycircularbuffer<double, 5> buff_1;

    // Display initial values of the buffer
    std::cout << "Initial values are..." << std::endl;

    std::cout << "The Array size is : " << buff_1.array_size() << std::endl;

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;


    // Inserting values
    insert_func(buff_1, 1.111);
    insert_func(buff_1, 2.222);
    insert_func(buff_1, 3.333);
    insert_func(buff_1, 4.444);
    insert_func(buff_1, 5.555);
    insert_func(buff_1, 6.666);



    // <---------------------------->

    // std::cout << "Removing Now..." << std::endl;

    // std::cout << "Removed " << buff_1.remove() << " value" << std::endl;

    // std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    // std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    // std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    // std::cout << "Removing Now..." << std::endl;

    // std::cout << "Removed " << buff_1.remove() << " value" << std::endl;

    // std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    // std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    // std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    // std::cout << "Removing Now..." << std::endl;

    // std::cout << "Removed " << buff_1.remove() << " value" << std::endl;

    // std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    // std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    // std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    // Program Done!

    std::cout << "Program Done!" << std::endl;
    return 0;
}
