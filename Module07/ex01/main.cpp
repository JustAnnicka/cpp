
#include "iter.hpp"
#include <iostream>

void test_intconst_function(const int &ref){
    std::cout << ref;
}
void test_int_function(int &ref){
    std::cout << ref;
}

void test_charconst_function(const char &ref){
    std::cout << ref;
}

void test_char_function(char &ref){
    std::cout << ref;
}

void test_stringconst_function(const std::string &ref){
    std::cout << ref;
}

int main( void ) {
int a[] = {1, 2, 3, 4};
char b[] = {'c', 'b', 'd', 'e'};
char c[4] ="BYE";
//char d[3];
int e;
char f;
const int x = -20;
std::string str[2] = {"Hello", "Bye"};
const std::string str2[3] = {"Const: ", "Hello", "Bye"};

::iter(a, sizeof(a) / sizeof(a[0]), test_int_function);
std::cout << std::endl;
::iter(a, sizeof(a) / sizeof(a[0]), test_intconst_function);
std::cout << std::endl;
::iter(b, sizeof(b) / sizeof(b[0]), test_charconst_function);
std::cout << std::endl;
::iter(c, sizeof(c) / sizeof(c[0]), test_charconst_function);
std::cout << std::endl;
::iter(str, 2, test_stringconst_function);
std::cout << std::endl;
::iter(str2, 3, test_stringconst_function);

std::cout << std::endl;
//FOR SOME REASON IF I USE THE ADDRESS IT COUNTS AS INITIALSED 
std::cout << &e << std::endl;
std::cout << sizeof(e)/sizeof(e) << std::endl;
//the type for the function needs and that is passed into the iter function dont match need to check for this?.
::iter(&e, sizeof(e)/sizeof(e), test_charconst_function);
std::cout << std::endl;
//Here again passing the address will cause the function to work
::iter(&e, sizeof(f)/sizeof(f), test_intconst_function);
std::cout << std::endl;
//gives giberish as well
::iter(b, sizeof(b) / sizeof(b[0]), test_intconst_function);
std::cout << std::endl;
//giving bigger number than array size seems fine for char array 
::iter(b, 10, test_charconst_function);
std::cout << std::endl;
//giving bigger number than array size seems fine for char array 
::iter(c, 10, test_charconst_function);
std::cout << std::endl;
//this should not be allowed (why does the function accept it on compile??)
::iter(c, x, test_charconst_function);
std::cout << std::endl;

//::iter(str, str.length(), test_charconst_function);

}
