#include <iostream>
//#include <locale>

int main (int argc, char *argv[])
{
    int i;
    //std::locale loc;
    i = 0;
    if (argc == 1)
       std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    else
    {
        while (++i < argc)
        {
            std::string str= argv[i];
            int j = 0;
            while(str[j] != '\0')
            {
                str[j] =  std::toupper(str[j]);
                j++;
            }
            std::cout << str;
        }
    }
    std::cout << "\n";
    return (0);
}
