
//template <typename A, typename L, typename F> void iter(A ptr[], L const len, void *f(F)){
template <typename A, typename L, typename F> void iter(A ptr[], L const len, F function){
    //A is address to an array -> A &ptr
    //L is len of array (can only be int or size_t ??)
    //F is function passed to each element of array
    // -> function passed can take the reference as const and non-const
    L i = 0;

    if (!ptr || ptr == 0)
        return ;
    /* for (L i = 0; i < len; i++)
        function(ptr[i]); */
    while (ptr[i] && i < len)
    {
        function(ptr[i]);
        i++;
    }
} 

//I think i might need to add type specific functions