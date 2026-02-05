
#include "iter.hpp"
#include <iostream>

void test_intconst_function(const int &ref){
    std::cout << ref<< " ";
}
void test_int_function(int &ref){
    std::cout << ref<< " ";
}

void test_charconst_function(const char &ref){
    std::cout << ref<< " ";
}

void test_char_function(char & ref){
    std::cout << ref<< " ";
}

void test_stringconst_function(const std::string & ref){
    std::cout << ref<< " ";
}

template < typename T >
void t_print(T & ref){
    std::cout << ref << " ";
}

int main( void ) {
int a[] = {1, 2, 3, 4};
char b[] = {'c', 'b', 'd', 'e'};
char const  c[4] ="BYE";
std::string str[2] = {"Hello ", "Bye"};
const std::string str2[3] = {"Const: ", "Hello ", "Bye"};

std::cout << "==== Normal function test ===" << std::endl;
iter(a, sizeof(a) / sizeof(a[0]), test_int_function);
std::cout << std::endl;
::iter(a, sizeof(a) / sizeof(a[0]), test_intconst_function);
std::cout << std::endl;
::iter(b, sizeof(b) / sizeof(b[0]), test_char_function);
std::cout << std::endl;
::iter(c, sizeof(c) / sizeof(c[0]), test_charconst_function);
::iter(str, 2, test_stringconst_function);
std::cout << std::endl;
::iter(str2, 3, test_stringconst_function);
std::cout << std::endl;
std::cout << "\n==== Template function test ===" << std::endl;
::iter(a, sizeof(a) / sizeof(a[0]), t_print<int>);
std::cout << std::endl;
::iter(b, sizeof(b) / sizeof(b[0]), t_print<char>);
std::cout << std::endl;
::iter(str, 2, t_print< std::string>);
std::cout << std::endl;
::iter(str2, 3, t_print<const std::string>);
std::cout << std::endl;
std::cout << "\n==== Len Error ===" << std::endl;
::iter(str, -2, test_stringconst_function);
std::cout << std::endl;
::iter(str2, 5, test_stringconst_function);
std::cout << std::endl;
::iter(c, 20, test_charconst_function);
std::cout << std::endl;
::iter(a, 20, test_intconst_function);
std::cout << std::endl;

return (0);

}

