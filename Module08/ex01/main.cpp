
/* Of course, you will write your own tests, and they will be far more thorough than the
ones below. Test your Span with at least 10,000 numbers. More would be even better */
#include "Span.hpp"
#include <ctime>
#include <climits>

int RandomNumber () { return (std::rand()%100000); }

int main()
{
	Span sp = Span(5);
	Span big = Span(10000);
	try{
		Span err = Span(UINT_MAX  + 1);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		sp.addNumber(11);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "==== BIG TEST ====" << std::endl;
	std::srand ( unsigned ( std::time(0) ) );
	std::vector<int> temp(10000);
	std::generate (temp.begin(), temp.end(), RandomNumber);
	try {
		big.multiAddNumber(temp.begin(), temp.end());
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}

/* EXPECTED OUTPUT:
$> ./ex01
2
14
$> 
 */