#ifndef P_QUEUE
#define P_QUEUE

#include "struct_info.h"
#include "heap.h"

template<typename T>
class PQueue
{
public:
    PQueue();

    bool insert(const T& value, int p);
    info<T> pop();
    T pop_item();
    T pop_priority();
    void pop_DEBUG();

    bool is_empty() const;
    int size() const;
    void print_tree() const;
    template<typename F>
    friend std::ostream& operator <<(std::ostream& os, const PQueue<F>& print_me);

private:
    heap<info<T> > Heap;

};

template<typename T>
PQueue<T>::PQueue()
{
   //nothing needs to be here.
}


template<typename T>
bool PQueue<T>::insert(const T &value, int p)
{
    //Inserts an info type into the heap.
    info<T> thingy(value, p);
    Heap.insert(thingy);
    return true;
}

template<typename T>
info<T> PQueue<T>::pop()
{
    return Heap.Pop();
}

template<typename T>
T PQueue<T>::pop_item()
{
    //Pops the heap and returns its corresponding item.
    return Heap.Pop()._item;
}

template<typename T>
T PQueue<T>::pop_priority()
{
    //Pops the heap and returns its corresponding priority.
    return Heap.Pop()._priority;
}

template<typename T>
void PQueue<T>::pop_DEBUG()
{
    //Pops and ordered list of the whole thing.
    while(!Heap.is_empty())
    {
        std::cout << Heap.Pop() << std::endl;
    }
}

template<typename T>
bool PQueue<T>::is_empty() const
{
    //return a bool if the heap is empty.
    return Heap.is_empty();
}

template<typename T>
int PQueue<T>::size() const
{
    //returns the size of the heap.
    return Heap.size();
}

template<typename T>
void PQueue<T>::print_tree() const
{
    //Prints the Heap which calls the << operator that we overloaded.
    std::cout << Heap;
}

template<typename F>
std::ostream& operator <<(std::ostream& os, const PQueue<F>& print_me)
{
    //Calls the print tree fucntion.
    print_me.print_tree();
    return os;
}


#endif // P_QUEUE

