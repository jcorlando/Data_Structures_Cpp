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


void remove_func(mycircularbuffer<double, 5> &object)
{
    std::cout << "Removing Now..." << std::endl;

    object.remove(); 

    std::cout << "The Front is at : " << object.get_front() << std::endl;

    std::cout << "The Back is at : " << object.get_back() << std::endl;

    std::cout << "The current length is : " << object.get_length() << std::endl << std::endl;
}





int main()
{
    // Create Circular buffer object
    mycircularbuffer<double, 5> buff_1;

    // <---------------------------->

    // Display initial values of the buffer
    std::cout << "Initial values are..." << std::endl;

    std::cout << "The Array size is : " << buff_1.array_size() << std::endl;

    std::cout << "The Front is at : " << buff_1.get_front() << std::endl;

    std::cout << "The Back is at : " << buff_1.get_back() << std::endl;

    std::cout << "The current length is : " << buff_1.get_length() << std::endl << std::endl;

    // <---------------------------->

    buff_1.print_buf();

    // <---------------------------->

    // Inserting values
    insert_func(buff_1, 1.111);
    buff_1.print_buf();
    insert_func(buff_1, 2.222);
    buff_1.print_buf();
    insert_func(buff_1, 3.333);
    buff_1.print_buf();
    insert_func(buff_1, 4.444);
    buff_1.print_buf();
    insert_func(buff_1, 5.555);
    buff_1.print_buf();
    insert_func(buff_1, 6.666);
    buff_1.print_buf();
    insert_func(buff_1, 7.777);

    // <---------------------------->

    // Removing values
    remove_func(buff_1);
    buff_1.print_buf();
    remove_func(buff_1);
    buff_1.print_buf();
    remove_func(buff_1);
    buff_1.print_buf();
    remove_func(buff_1);
    buff_1.print_buf();
    remove_func(buff_1);
    buff_1.print_buf();
    remove_func(buff_1);

    // <---------------------------->

    // Inserting values
    insert_func(buff_1, 8.888);
    buff_1.print_buf();
    insert_func(buff_1, 9.999);
    buff_1.print_buf();
    remove_func(buff_1);
    buff_1.print_buf();
    insert_func(buff_1, 10.1);
    buff_1.print_buf();
    insert_func(buff_1, 11.1);
    buff_1.print_buf();
    insert_func(buff_1, 12.1);
    buff_1.print_buf();
    insert_func(buff_1, 13.1);
    buff_1.print_buf();

    // <---------------------------->

    // Program Done!
    std::cout << "Program Done!" << std::endl;

    return 0;
}
