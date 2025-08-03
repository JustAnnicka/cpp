#include <iostream>

void    to_upper(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    std::cout <<  str;
 }

int main (int argc, char *argv[])
{
    int i;

    i = 0;
    if (argc == 1)
       std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    else
    {
        while (++i < argc)
            to_upper(argv[i]);
    }
    std::cout << "\n";
    return (0);
}
/* 
//ALTERNATIVE
#include <iostream>
#include <stdlib.h>
#include <string.h>

std::string to_upper(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = std::toupper(str[i]);
        i++;
    }
    return (str);
}

int main (int argc, char *argv[])
{
    int i;

    i = 0;
    if (argc == 1)
       std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    else
    {
        for (i = 1; i < argc; i++)
             std::cout << to_upper(argv[i]);
    }
    std::cout << std::endl;
    return (0);
} */