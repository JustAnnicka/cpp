#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

int main()
{
    Array<int> numbers(10);
    int* mirror = new int[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        const int value = rand();
     
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    Array<int> ref;
    ref = numbers;
    Array<int> test2(numbers);
    Array<std::string> s_test(5);
 

    for (int i = 0; i < 10; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        test2[i] = test2[i] + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        if (test2[i] == numbers[i])
        {
            std::cerr << "Error with copys sharing address" << std::endl;
            return 1;
        }
    }

    delete[] mirror;
    return (0);
}

/* int main()
{
    int * a = new int(); //array of size 1 is created (we can dynamically add to it, but this causes errors in valgrind (supresssed))
    int * b = new int[1]; //array has to be initialized with value (unless initializer present)

     std::cout << *a << std::endl;
    for (int i = 0; i < 2; i++)
        a[i] = i;
    for (int j = 0; j < 2; j++)
       std::cout <<  a[j] << std::endl;
    
    for (int x = 0; x < 1; x++)
        b[x] = x;
    for (int y = 0; y < 1; y++)
       std::cout <<  b[y] << std::endl;
    //why can i go over array size??
    
    std::cout << a << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << b << std::endl;

    delete a;
    delete[] b;
    return (0);
} */
/* int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */