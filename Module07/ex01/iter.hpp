
#include <iostream>
//template <typename A, typename L, typename F> void iter(A ptr[], L const len, void *f(F)){
template <typename T, typename F> void iter(T ptr[],const int len, F function){
    //A is address to an array -> A &ptr
    //L is len of array (can only be int or size_t ??)
    //F is function passed to each element of array
    // -> function passed can take the reference as const and non-const
    
    //can I use the iterator header?
    if (!ptr)
        return ;
    for (int i = 0; i < len; i++)
        function(ptr[i]);
 
} 

//I think i might need to add type specific functions -> needed for string!!!