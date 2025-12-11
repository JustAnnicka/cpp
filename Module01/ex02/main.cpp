#include <iostream>
#include <string>

int	main()
{
	std::string  s = "HI THIS IS BRAIN";
	std::string  *stringPTR = &s;
	std::string  &stringREF = s;
	
	std::cout << "The string address      " << &s << std::endl;
	std::cout << "The stringPTR address   " << stringPTR << std::endl;
	std::cout << "The stringREf address   " << &stringREF << std::endl;

	std::cout << "\nThe string content      " << s << std::endl;
	std::cout << "The stringPTR content   " << *stringPTR << std::endl;
	std::cout << "The stringREF content   " << stringREF << std::endl;

	stringREF = "hola";

	std::cout << "\nThe string content      " << s << std::endl;
	std::cout << "The stringREF content   " << stringREF << std::endl;
	return (0);
}