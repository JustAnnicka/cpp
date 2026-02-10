
#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
//#include <string>
#include <algorithm>
#include <stdexcept>

class ValNotFound : public std::exception{
	public:
		virtual const char* what() const throw(){
			return ("Value not found.");
		}
};

template <typename T> typename T::iterator easyfind(T container, int i){

	typename T::iterator it = std::find(container.begin(), container.end(), i);
	
	if (it == container.end())
		throw(ValNotFound());
	//std::cout << "The first occurace is: " << *it << std::endl;
	//std::cout << "The first occurace is: " << *it << std::endl;
	return (it);
} 
/* 
template <> void easyfind <std::string>(std::string container, int i){

	typename T::iterator it;

	int array[1];
	array[0] = i;
	
	//find first of works for chars and ints (not for Strings)
	it = find_first_of(container.begin(), container.end(), array, array+1);
	
	if (it != container.end())
	{
		std::cout << "The first occurace is: " << *it << std::endl;
		std::cout << "Difference to start is: " << std::distance(container.begin(), it) << std::endl;
	}
	else
		std::cout << i << " not found in container" << std::endl;

	//maybe add checks for other types of container (ie if its a char or string it should give other output)
}  */

#endif
//Assuming T is a container of integers
// -> the function has to find the first occurance of the second parameter in the first parameter
// ie. find first occurance of i in the  T container (array)
// ---> if no occurance is found either:
// -----> throw and expetion
// -----> OR return an error value of your choice
