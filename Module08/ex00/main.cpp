#include "easyfind.hpp"

int	main()
{
	int mychars[] = {'a','b','c','A','B','C'};
  	std::vector<char> haystack (mychars,mychars+6);
  	
	
	std::vector<char>::iterator it;
	::easyfind(haystack, 'A');
	::easyfind(haystack, 'z');
	//std::cout << "It is " << *it << std::endl;

	return (0);
}

