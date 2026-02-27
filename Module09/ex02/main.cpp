
#include "PmergeMe.hpp"

//Your program must be able to use a positive integer sequence as an argument.
//Your program must use the merge-insert sort algorithm to sort the positive integer sequence.
	// Ford-Johnson algorithm.
//If an error occurs during program execution, an error message should be displayed on the standard error.
int main(int argc, char *argv[]){
	{
		if (argc < 2)
			return (std::cerr << "Error: need a positive number sequence" << std::endl , 1);
		try{
			PmergeMe merge(argc, argv);
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
/* 
	{
		try{
			PmergeMe merge;
			merge.johnsonFord(argc, argv);
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	} */
}


/* 
You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.

It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.
*/

// DO I have to check for a singular argument for the sequence? eg "1 2 3 4 5"
/* 
EXAMPLE TEST

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>

*/