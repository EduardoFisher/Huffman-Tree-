#ifndef LEVELS
#define LEVELS

#include <iostream>
#include <iomanip>

class levels
{
public:
    levels(unsigned int level = 0, int tab = 4):_level(level), _tab(tab){}
    unsigned int get_level() { return _level; }
    friend std::ostream& operator <<(std::ostream& os, const levels& print_me)
    {
        os << "[L:" << print_me._level << "]" << std::setw(print_me._level * print_me._tab);
        return os;
    }
private:
    unsigned _level;
    int _tab;
};


#endif // LEVELS

