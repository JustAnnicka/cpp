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
	int id;
}t_pairs ; 

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(int argc, char *argv[]);
		PmergeMe(PmergeMe & other);
		PmergeMe & operator=(const PmergeMe & other);
		~PmergeMe();

		void fill_containers(int argc, char *argv[]);
		void johnsonFord(int argc, char *argv[]);

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
		std::deque<unsigned int> _deque; //these are the mains
		std::deque<t_pairs> _dsort; //these are the mains
		std::vector<unsigned int> _vector; //these are the mains
		//std::vector<unsigned int> _vsort; //these are the mains
		int _tracker; //this would be a global
		//std::list<unsigned int> _list;
		std::clock_t _dequeTime; //if I make them const they have to be initialised at start
		std::clock_t _vectorTime; //might not need this since clock gives ticks since start of program:
		void dequeSort(std::deque<unsigned int> aux);
		int JacobThal(size_t n);
		std::deque<int> JacobThalSequence(size_t n);
		std::deque<unsigned int> pairing(std::deque<unsigned int> aux);
		//std::deque<unsigned int> recursive_pairing(std::deque<t_pairs> aux); //these could be templates
		//void insertion(); //these could be templates
		//void MakePairs(std::deque<std::set<unsigned int> > container);
};


 #endif