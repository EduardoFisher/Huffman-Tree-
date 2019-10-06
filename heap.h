#ifndef HEAP
#define HEAP

#include <cassert>
#include "levels.h"

const int SIZE = 100000;

template<typename T>
class heap
{
public:
    heap();
    void insert(const T& insert_me);
    T Pop();

    bool is_empty() const;
    int size() const;
    int capacity() const;
    template<typename F>
    friend std::ostream& operator << (std::ostream& os, const heap<F>& print_me);
private:
    T heaping[SIZE];        //The array that holds all the items.
    unsigned int how_many;  //The number of how many items are in the array.
    void print_tree(std::ostream& os = std::cout) const;
    void print_tree(unsigned int root, levels cLevel, std::ostream& os = std::cout) const;


    bool is_leaf(int i) const;
    unsigned int parent_index(int i) const;
    unsigned int left_child_index(int i)const;
    unsigned int right_child_index(int i) const;
    unsigned int big_child_index(int i) const;
    unsigned int small_child_index(int i) const;
    void swap_with_parent(int i);
};

template<typename T>
heap<T>::heap()
{
    how_many = 0;
}

template<typename T>
void heap<T>::insert(const T &insert_me)
{
    //Then we insert the item into the last part of the array.
    heaping[how_many] = insert_me;
    //Then check to see if it needs to be swapped with its parent.
    if(how_many > 0)
    {
        int where_are_we = how_many;
        //We will keep swapping with our parent until we are,
        //a). at the top.
        //b). its parent is smaller.
        while(heaping[parent_index(where_are_we)] > heaping[where_are_we])
        {
            swap_with_parent(where_are_we);
            where_are_we = parent_index(where_are_we);
        }
    }
    //Add one to list.
    how_many++;
}

template<typename T>
T heap<T>::Pop()
{
    if(is_empty())
    {
        assert(how_many = 0);
    }
    //Subtract one from the list so we can over ride it later on.
    how_many--;
    //We start at 0.
    int i = 0;
    //We first hold the smallest item in the array.
    T hold = heaping[i];
    //Now replace it with the item at the end of the array.
    heaping[i] = heaping[how_many];
    //Now keep swapping with its smallest child.
    while(heaping[i] > heaping[small_child_index(i)])
    {
        if(small_child_index(i) > how_many)
            break;
        int where_are_we = small_child_index(i);
        swap_with_parent(small_child_index(i));
        i = where_are_we;
    }
    return hold;

}

template<typename F>
std::ostream& operator << (std::ostream& os, const heap<F>& print_me)
{
    print_me.print_tree(os);
    return os;
}

template<typename T>
int heap<T>::capacity() const
{
    return SIZE;
}

template<typename T>
int heap<T>::size() const
{
    return how_many;
}

template<typename T>
bool heap<T>::is_empty() const
{
    return (how_many == 0);
}

template<typename T>
void heap<T>::print_tree(std::ostream &os) const
{
    levels cLevel(0);
    print_tree(0, cLevel, os);
}

template<typename T>
void heap<T>::print_tree(unsigned int root, levels cLevel, std::ostream &os) const
{
    if(root < how_many)
    {
        print_tree(right_child_index(root), cLevel.get_level() + 1);
        os << cLevel << "[" << heaping[root] << "]" << std::endl;
        print_tree(left_child_index(root), cLevel.get_level() + 1);
    }
}

template<typename T>
bool heap<T>::is_leaf(int i) const
{
    if(left_child_index(i) > how_many)
        return true;
    return false;
}

template<typename T>
unsigned int heap<T>::parent_index(int i) const
{
    return static_cast<unsigned>(i - 1) / 2;
}

template<typename T>
unsigned int heap<T>::left_child_index(int i) const
{
    return static_cast<unsigned>(2*i + 1);
}

template<typename T>
unsigned int heap<T>::right_child_index(int i) const
{
    return static_cast<unsigned>(2*i + 2);
}

template<typename T>
unsigned int heap<T>::big_child_index(int i) const
{
    if(heaping[left_child_index(i)] > heaping[right_child_index(i)])
        return left_child_index(i);
    return right_child_index(i);
}

template<typename T>
unsigned int heap<T>::small_child_index(int i) const
{
    if(heaping[left_child_index(i)] < heaping[right_child_index(i)])
        return left_child_index(i);
    return right_child_index(i);
}

template<typename T>
void heap<T>::swap_with_parent(int i)
{
    T temp = heaping[parent_index(i)];
    heaping[parent_index(i)] = heaping[i];
    heaping[i] = temp;
}

#endif // HEAP

