#ifndef MYCIRCULARBUFFER_H
#define MYCIRCULARBUFFER_H

#include <array>
#include <memory>

template<class T, unsigned int size>
class mycircularbuffer
{
private:
    std::array<T, size> array;
    unsigned int front;
    unsigned int current_length;
public:
    // Constructor
    mycircularbuffer();

    


    // Get the Front Pointer
    unsigned int get_front() const;
    
    // Get the Back Pointer
    unsigned int get_back() const;

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


template<class T, unsigned int size>
int mycircularbuffer<T, size>::array_size() const   { return array.size(); }


template<class T, unsigned int size>
unsigned int mycircularbuffer<T, size>::get_front() const   { return this->front; }


template<class T, unsigned int size>
unsigned int mycircularbuffer<T, size>::get_back() const   { return this->front; }


#endif // MYCIRCULARBUFFER_H
