#ifndef MYCIRCULARBUFFER_H
#define MYCIRCULARBUFFER_H
#include <iostream>
#include <array>
#include <vector>

template<class T, unsigned int size>
class mycircularbuffer
{
private:
    std::array<T, size> array;
public:
    // Constructor
    mycircularbuffer();

    int array_size() const;

    T get_at(const int &value) const;
};



// Constructor
template<class T, unsigned int size>
mycircularbuffer<T, size>::mycircularbuffer() { ; }


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

#endif // MYCIRCULARBUFFER_H
