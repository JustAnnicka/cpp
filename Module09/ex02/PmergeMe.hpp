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
		void printDeque(); //make this template function

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
		/* template <typename Container> 
		Container johnsonFord(Container& aux); */
		std::deque<unsigned int> johnsonFord_deq(std::deque<unsigned int> aux);
		std::vector<unsigned int> johnsonFord_vec(std::vector<unsigned int> aux);
};

/* template <typename Container> 
Container PmergeMe::JacobThalSequence(size_t n){
	int Jn;
	size_t i = 1;
	Container JTSequence;
	while (i++ < n){
		Jn = JacobThal(i);
		if (Jn >= (int)n)
			break ;
		if (Jn < (int)n) 
			JTSequence.push_back(Jn);
		else
			JTSequence.push_back(n);
		if (i >= 3 && JTSequence.size() < n){
			Jn = *JTSequence.rbegin();
			JTSequence.push_back(Jn - 1);
		}
	}
	if (JTSequence.size() < n)
	{
		for (size_t j = n; JTSequence.size() < n; j--)
			JTSequence.push_back((int)j);
	}
	return (JTSequence);
} *//* 
template <typename Container> 
Container PmergeMe::johnsonFord(Container& aux){
	if (aux.size() <= 1){
		return (aux);
	}
	Container max_chain; 
	Container min_chain; 
	Container sorted_chain; 
	size_t size = aux.size() / 2;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux.front();
		aux.erase(aux.begin());	
		t_pairs p(x, aux.front());
		aux.erase(aux.begin());
		max_chain.push_back(p.max);
		min_chain.push_back(p.min);
	}
	if (!aux.empty())
			max_chain.push_back(aux[0]);
	sorted_chain = johnsonFord(max_chain);	
	if (min_chain.size() == 1)
		sorted_chain.insert(sorted_chain.begin(), min_chain[0]);
	else{
		std::deque<unsigned int> x = JacobThalSequence(min_chain.size());
		for (size_t i = 0; i < x.size() ; i++){
			std::deque<unsigned int>::iterator it = lower_bound(sorted_chain.begin(), std::find(sorted_chain.begin(), sorted_chain.end(),max_chain[x[i] - 1]), min_chain[x[i] -1]);
			sorted_chain.insert(it, min_chain[x[i] - 1]);
		}
	}
	return (sorted_chain);
}
 */

 #endif