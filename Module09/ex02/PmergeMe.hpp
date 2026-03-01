#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <list> //mmaybe delete this
#include <stack>
#include <set> // delete this
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <utility> //for pairs
#include <iterator>
#include <climits>
#include <typeinfo>
#include <algorithm>

typedef struct s_pairs{
	s_pairs(unsigned int a, unsigned int b){
		if (a > b){
			min = b;
			max = a;
		}
		else{
			min = a;
			max = b;	
		}
	}
	unsigned int min; //b
	unsigned int max; //a
}t_pairs ; 

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(int argc, char *argv[]);
		PmergeMe(PmergeMe & other);
		PmergeMe & operator=(const PmergeMe & other);
		~PmergeMe();

		void fill_containers(int argc, char *argv[]);
		void initialise(int argc, char *argv[]);
		template <typename T>
		void printContainer(T container);

		class InvalidInput : public std::exception{
			public:
				virtual const char * what ()const throw();
		};
		class EmptyInput : public std::exception{
			public:
				virtual const char * what ()const throw();
		};
		class DuplicateDetected : public std::exception{
			public:
				virtual const char * what ()const throw();
		};
	private:
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _vector;
		int JacobThal(size_t n);
		std::deque<unsigned int> JacobThalSequence(size_t n);
		std::deque<unsigned int> johnsonFord_deq(std::deque<unsigned int> aux);
		std::vector<unsigned int> johnsonFord_vec(std::vector<unsigned int> aux);
};

template <typename T>
void PmergeMe::printContainer(T container){
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}


 #endif