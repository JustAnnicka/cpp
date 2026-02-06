
#ifndef ITER_HPP
 #define ITER_HPP

#include <iostream>

template <typename T, typename F> void iter(T &ptr, const size_t len, F function){
    if (!ptr)
        return ;
    if (len > sizeof(ptr) / sizeof(ptr[0]))
    {
        std::cout << "Error\nLen does not match array size" << std::endl;
        return ;
    }
    for (size_t i = 0; i < len; i++)
    {
        function(ptr[i]);
    }
}

#endif
