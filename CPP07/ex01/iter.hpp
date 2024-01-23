#pragma once
# include <iostream>
# include <limits.h>

template<typename T>
void iter(T* address, size_t len, void (*f)(T&))
{
    for (int i = 0; i < static_cast<int>(len); i++)
    {
        f(address[i]);
    }
}

template<typename T>
void print(T& something)
{
    std::cout << something << std::endl;
}
