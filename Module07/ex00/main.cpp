#include "whatever.hpp"
#include <iostream>

int main( void ) {
int a = 2;
int b = 3;
std::cout << "=== Before int swap: ===" << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;
::swap( a, b );
std::cout << "=== After int swap: ===" << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "=== Before string swap: ===" << std::endl;
std::cout << "c = " << c << ", d = " << d << std::endl;
::swap(c, d);
std::cout << "=== After string swap: ===" << std::endl;
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
std::cout << "=== Other parameter types: ===" << std::endl;
std::cout << "min(3.5, 4.5) = " << ::min<double>(3.5, 4.5) << std::endl;
std::cout << "min(2.0f, 42.0f) = " << ::min<float>(2.0f, 42.0f) << std::endl;
std::cout << "min('c', 'f') = " << ::min<char>('c', 'f') << std::endl;

return 0;
} 
