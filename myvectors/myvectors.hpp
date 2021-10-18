#ifndef MYVECTORS_H
#define MYVECTORS_H

#include <array>


template <class T, unsigned int size>
class myvector
{
    private:
        std::array<T, size> vect;
    public:

    // Constructor
    myvector();

};


// Constructor
template<class T, unsigned int size>
myvector<T, size>::myvector()
{
    ;
}






#endif // MYVECTORS_H
