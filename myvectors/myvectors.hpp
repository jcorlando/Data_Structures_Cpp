#ifndef MYVECTORS_H
#define MYVECTORS_H
#include <array>
#include <initializer_list>


template <class T, unsigned int dimensions>
class myvector
{
    private:
        std::array<T, dimensions> vect;
    public:
    // Default Constructor
    myvector();
    
    // Overloaded Constructor
    myvector( std::initializer_list<T> list );

    // Overload bracket[]
    T& operator [](int i);

    // Const Version Overload bracket[]
    const T& operator [](int  i) const;


};


// Default Constructor
template<class T, unsigned int dimensions>
myvector<T, dimensions>::myvector()
{
    for (auto &each : vect) each = 0;
}



// <---- Constructor With Arguments definition
template<class T, unsigned int dimensions>
myvector<T, dimensions>::myvector( std::initializer_list<T> list )
{
    for (auto it = list.begin(); it != list.end(); it++)
    {
        this->vect[it - list.begin()] = *it;
    }
}


// <---------- This is for Non-Const Objects
// Implementation of [] operator.  This function must return
// a reference as array element can be put on left side
template<class T, unsigned int dimensions>
T& myvector<T, dimensions>::operator [](int i)
{
    if(i < 0) return vect.at(0);
    else if( i >= vect.size() ) return vect.back();
    else return vect.at(i);
}


// <---------- This is for Const Objects
template<class T, unsigned int dimensions>
const T& myvector<T, dimensions>::operator [](int  i) const
{
    if(i < 0) return vect.at(0);
    else if( i >= vect.size() ) return vect.back();
    else return vect.at(i);
}


#endif // MYVECTORS_H
