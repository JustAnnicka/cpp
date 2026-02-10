
/* Of course, you will write your own tests, and they will be far more thorough than the
ones below. Test your Span with at least 10,000 numbers. More would be even better */
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

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
	return 0;
}

/* EXPECTED OUTPUT:
$> ./ex01
2
14
$> 
 */