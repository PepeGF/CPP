#pragma once
# include <iostream>
# include <limits.h>

template<typename T>
void iter(T* address, int len, void (*f)(T&))
{
    for (int i = 0; i < len; i++)
    {
        f(address[i]);
    }
}

template<typename T>
void print(T& something)
{
    std::cout << something << std::endl;
    return;
}

/* class Awesome
{
    public:
        Awesome(void): _n(42){return;}
        int get(void) const {return this->_n;}
    private:
        int _n;
};

std::ostream& operator<<(std::ostream &o, Awesome const &rhs)
{o << rhs.get(); return o;} */