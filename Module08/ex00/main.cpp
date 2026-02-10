#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <string>

int	main()
{
	int ints[] = {'a','b','c','A','B','C'};
  	std::vector<int> haystack (ints,ints+6);

	char chars[] = {'a','b','c','A','B','C'};
  	std::deque<char> haystack2 (chars,chars+6);
	/* 
	std::string str[] = {"Hallo","this","is","a","string","!!!"};
  	std::list<std::string> haystack3 (chars,chars+6); */
	try{
		::easyfind(haystack, 'A');
		::easyfind(haystack2, 'a');
		::easyfind(haystack, 'z');
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	//::easyfind(haystack3, 'a');
	//std::cout << "It is " << *it << std::endl;

	return (0);
}

