#include "heap.h"
#include "p_queue.h"

using namespace std;

void min_heap_test();

void p_Queue_test();

void p_Queue_test2();

template<typename T>
void printCodes( info<T>* root, string str);

int main()
{
    //min_heap_test();
    p_Queue_test();
    //p_Queue_test2();

    return 0;
}

void min_heap_test()
{
    heap<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);

    cout << a << endl;
    a.Pop();
    cout << a << endl;
}

void p_Queue_test2()
{
    PQueue<char> p;
    p.insert('a', 4);
    p.insert('v', 7);
    p.insert('b', 13);
    p.insert('c', 2);
    cout << p << endl;
}

void p_Queue_test()
{
    //int b, c;
    info<char>* left;
    info<char>* right;
    info<char>* root;

    PQueue<info<char>* > a;
    a.insert(new info<char>('b', 9), 9);
    a.insert(new info<char>('c', 12), 12);
    a.insert(new info<char>('d', 13), 13);
    a.insert(new info<char>('e', 16), 16);
    a.insert(new info<char>('f', 45), 45);
    a.insert(new info<char>('a', 5), 5);
    //a.insert(new info<char>('g', 60), 60);

    cout << a << endl;

//        while(a.size() != 1)
//        {

//            left = a.pop()._item;

//            right = a.pop()._item;

//            root = new info<char>('#', left->Get_priority() + right->Get_priority());

//            root->_left = left;
//            root->_right = right;

//            a.insert(root, root->_priority);
//        }

//        root = a.pop()._item;

//        printCodes(root, "");

}

// Prints huffman codes from
// the root of Huffman Tree.
template<typename T>
void printCodes( info<T>* root, string str)
{

    if (!root)
        return;

    if (root->_item != '#')
        cout << root->_item << ": " << str << "\n";

    printCodes(root->_left, str + "0");
    printCodes(root->_right, str + "1");
}

