#ifndef STRUCT_INFO
#define STRUCT_INFO

#include <iostream>

template<typename T>
struct info
{
    T _item;
    int _priority;

    info<T>* _left;
    info<T>* _right;

    info();
    info(T i, int p);

    int Get_priority();

    template<typename F>
    friend std::ostream& operator <<(std::ostream& os, const info<F>& print_me);

    template<typename F>
    friend bool operator <(const info<F>& lhs, const info<F> rhs);

    info<T>& operator =(const info<T>& rhs);

    template<typename F>
    friend bool operator >(const info<F>& lhs, const info<F> rhs);
};

template<typename T>
int info<T>::Get_priority()
{
    return this->_priority;
}

template<typename T>
info<T>::info()
{
    _item = 0;
    _priority = 0;
    _left = NULL;
    _right = NULL;
}

template<typename T>
info<T>::info(T i, int p)
{
    //Sets the info type.
    _item = i;
    _priority = p;
    _left = NULL;
    _right = NULL;
}

template<typename F>
std::ostream& operator <<(std::ostream& os, const info<F>& print_me)
{
    //Prints the info type properly, Item first, then Priority.
    os << "I:[" << print_me._item << "]" << "|" << "P:[" << print_me._priority << "]";
    return os;
}

template<typename F>
bool operator <(const info<F>& lhs, const info<F> rhs)
{
    //Checks priority.
    if(lhs._priority < rhs._priority)
        return true;
    return false;
}

template<typename F>
bool operator >(const info<F>& lhs, const info<F> rhs)
{
    //Checks priority.
    return (lhs._priority > rhs._priority);
}

template<typename T>
info<T>& info<T>::operator =(const info<T>& rhs)
{
    if(this != &rhs)
    {
        this->_item = rhs._item;
        this->_priority = rhs._priority;
    }
    return *this;
}

#endif // STRUCT_INFO

