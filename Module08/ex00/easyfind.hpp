
#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <iostream>
//Following Headers are STL headers
//#include <array> is c++11
//#include <forward_list> is c++11

// Sequence Containers 
#include <vector>
#include <deque>
#include <list>

/* // Container Adaptors
#include <stack>
#include <queue> */


/* //Associatice Containers
#include <set>
#include <multiset>
#include <map>
#include <multimap>
 */


#include <algorithm>
//#include <iterator> // these are the pointer like objects (needed to connect stl algoriths with the containers)
// check if i am allowed to use iterators. (they should be included in the other headers actually)
//template <typename T> T::iterator easyfind(T container, int i){
template <typename T> void easyfind(T container, int i){

	typename T::iterator it;
	//typename T::iterator needle;

	int array[1];
	array[0] = i;

	
	//.begin() & .end(),  size(), resize() works for:
	// ->vector, deque, list
	
	it = find_first_of(container.begin(), container.end(), array, array+1);
	
	if (it != container.end())
	{
		std::cout << "The first occurace is: " << *it << std::endl;
		std::cout << "Difference to start is: " << std::distance(container.begin(), it) << std::endl;
	}
	else
		std::cout << i << " not found in container" << std::endl;

	//maybe add checks for other types of container (ie if its a char or string it should give other output)


	// Dont think this is correct as it needs an iterator for the last two values (ie in an array)
} 

#endif
//Assuming T is a container of integers
// -> the function has to find the first occurance of the second parameter in the first parameter
// ie. find first occurance of i in the  T container (array)
// ---> if no occurance is found either:
// -----> throw and expetion
// -----> OR return an error value of your choice

// For inspo check how standard containers behave


// You dont have to handle associative containers!!
