#ifndef MYCIRCULARBUFFER_H
#define MYCIRCULARBUFFER_H

#include <array>
#include <memory>


// FIFO (First In First Out) Data Structure
template<class T, unsigned int size>
class mycircularbuffer
{
private:
    std::array<T, size> array;
    unsigned int front;
    unsigned int back;
    unsigned int current_length;
public:
    // Constructor
    mycircularbuffer();

    // Insert new value if space avaliable
    void insert(T value);

    // Remove value from FIFO
    void remove();

    // Print entire Buffer Array
    void print_buf();

    // Get the Front Position
    unsigned int get_front() const;
    
    // Get the Back Position
    unsigned int get_back() const;

    // Get the Current Length
    unsigned int get_length() const;

    // Get the full array size
    int array_size() const;

    // get the value at the specified index
    T get_at(const int &value) const;
};



// Constructor
template<class T, unsigned int size>
mycircularbuffer<T, size>::mycircularbuffer()
{
    front = 0;
    back = 0;
    current_length = 0;
}


template<class T, unsigned int size>
T mycircularbuffer<T, size>::get_at(const int &value) const
{
    try
        { return array.at(value); }
    
    catch(const std::exception& e)
        { ; }
}


// Print entire Buffer Array
template<class T, unsigned int size>
void mycircularbuffer<T, size>::print_buf()
{
    std::cout << "|";
    for (auto each : array) std::cout << each << "|";
    std::cout << std::endl << std::endl;
}


template<class T, unsigned int size>
int mycircularbuffer<T, size>::array_size() const   { return array.size(); }


template<class T, unsigned int size>
unsigned int mycircularbuffer<T, size>::get_front() const   { return this->front; }


template<class T, unsigned int size>
unsigned int mycircularbuffer<T, size>::get_back() const   { return ( this->back ); }


template<class T, unsigned int size>
unsigned int mycircularbuffer<T, size>::get_length() const   { return ( this->current_length ); }


template<class T, unsigned int size>
void mycircularbuffer<T, size>::insert(T value)
{
    if( current_length < array.size() )
    {
        array[back] = value;
        current_length = current_length + 1;
        back = ( back + 1 ) % ( array.size() );
    }
    else
    {
        std::cout << "The FIFO is Full...  Cannot Insert" << std::endl;
    }
}


template<class T, unsigned int size>
void mycircularbuffer<T, size>::remove()
{
    T print_value;
    if( current_length > 0 )
    {
        print_value = array[front];
        current_length = current_length - 1;
        front = ( front + 1 ) % ( array.size() );
        std::cout << "Removed " << print_value << " value" << std::endl;
    }
    else
    {
        std::cout << "The FIFO is Empty...  Cannot Remove" << std::endl;
    }
}
#endif // MYCIRCULARBUFFER_H
