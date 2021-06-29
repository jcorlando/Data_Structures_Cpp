#ifndef MYCIRCULARBUFFER_H
#define MYCIRCULARBUFFER_H
#include <iostream>
#include <vector>

template<class T>
class mycircularbuffer
{
private:
    std::vector<T> vectr;
public:
    mycircularbuffer();
    int vectr_size() const;
    void insert_end(const T &value);
    T get_at(const int &value) const;
};

template<class T>
mycircularbuffer<T>::mycircularbuffer() { ; }

template<class T>
T mycircularbuffer<T>::get_at(const int &value) const
{
    return vectr.at(value);
}

template<class T>
void mycircularbuffer<T>::insert_end(const T &value)
{
    vectr.push_back(value);
}

template<class T>
int mycircularbuffer<T>::vectr_size() const
{
    return vectr.size();
}

#endif // MYCIRCULARBUFFER_H
