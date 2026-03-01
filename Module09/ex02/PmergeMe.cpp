
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
	//std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(int argc, char *argv[]){
	//std::cout << "PmergeMe string array constructor called" << std::endl;
	this->initialise(argc, argv);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::initialise(int argc, char *argv[]){
	clock_t time;
	this->fill_containers(argc, argv);
	std::cout << "Before: ";
	printContainer(_deque);
	time = clock();
	_deque = johnsonFord_deq(_deque);
	time = clock() - time;
	std::cout << "After: ";
	printContainer(_deque);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << std::fixed << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl; //need to set precision to ensure it doesnt to scientific notation
	
	time = clock() - time;
	_vector = johnsonFord_vec(_vector);
	//printContainer(_vector);
	time = clock() - time;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << ((float)time / CLOCKS_PER_SEC) << " seconds" << std::endl;
}

int PmergeMe::JacobThal(size_t n){
	int Jn;
	int x;
	if (n == 0)
		return (0);
	if (n <= 2)
		return (1);
	Jn = JacobThal(n - 1); 
	x = Jn + 2 * (JacobThal(n - 2));
	return (x);
}

std::deque< unsigned int> PmergeMe::JacobThalSequence(size_t n){
	int Jn;
	size_t i = 1;
	std::deque< unsigned int> JTSequence;
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
}

std::deque<unsigned int> PmergeMe::johnsonFord_deq(std::deque<unsigned int> aux){
	if (aux.size() <= 1){
		return (aux);
	}
	std::deque<unsigned int> max_chain; 
	std::deque<unsigned int> min_chain; 
	std::deque<unsigned int> sorted_chain; 
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
			max_chain.push_back(*aux.rbegin());
	sorted_chain = johnsonFord_deq(max_chain);	
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

std::vector<unsigned int> PmergeMe::johnsonFord_vec(std::vector<unsigned int> aux){
	if (aux.size() <= 1){
		return (aux);
	}
	std::vector<unsigned int> max_chain; 
	std::vector<unsigned int> min_chain; 
	std::vector<unsigned int> sorted_chain; 
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
	sorted_chain = johnsonFord_vec(max_chain);	
	if (min_chain.size() == 1)
		sorted_chain.insert(sorted_chain.begin(), min_chain[0]);
	else{
		std::deque<unsigned int> x = JacobThalSequence(min_chain.size());
		for (size_t i = 0; i < x.size() ; i++){
			std::vector<unsigned int>::iterator it = lower_bound(sorted_chain.begin(), std::find(sorted_chain.begin(), sorted_chain.end(),max_chain[x[i] - 1]), min_chain[x[i] -1]);
			sorted_chain.insert(it, min_chain[x[i] - 1]);
		}
	}
	return (sorted_chain);
}

void PmergeMe::fill_containers(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string temp = argv[i];
		if (temp.empty())
			throw(EmptyInput());
		size_t size = temp.size();
		for (size_t j = 0; j < size; j++){
			if (!std::isdigit(temp[j]))
			{
				std::cout << "argc: " << i  << "char: " << temp[i] << std::endl;
				throw(InvalidInput());
			}
		}
		char* end;
		long n = std::strtol(temp.c_str(), &end, 10);
		if (n < 0 || n > INT_MAX)
			throw(InvalidInput());
		if (!_deque.empty()){
			size = _deque.size();
			for(size_t z = 0; z < size; z++){
				if (n == _deque[z])
					throw(DuplicateDetected());
			}
		}
		_deque.push_back(static_cast<unsigned int>(n));
		_vector.push_back(static_cast<unsigned int>(n));
	}
}

// === EXCEPTIONS ===

const char * PmergeMe::InvalidInput::what() const throw(){
	return ("Error: Invalud Input. Only positive integers allowed");
}
const char * PmergeMe::EmptyInput::what () const throw(){
	return ("Error: Empty input");
}
const char * PmergeMe::DuplicateDetected::what() const throw(){
	return ("Error: Duplicate detected");
}