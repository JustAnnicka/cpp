
#include "PmergeMe.hpp"

/* 
Here are some additional guidelines on the information you should display line by line
on the standard output:
• On the first line you must display an explicit text followed by the unsorted positive
integer sequence.
• On the second line you must display an explicit text followed by the sorted positive
integer sequence.
• On the third line, you must display an explicit message indicating the time taken
by your algorithm, specifying the first container used to sort the positive integer
sequence.
• On the last line you must display an explicit text indicating the time used by
your algorithm by specifying the second container used to sort the positive integer
sequence

*/

PmergeMe::PmergeMe(){
	//std::cout << "PmergeMe constructor called" << std::endl;
	//do i have to init time to NULL?

}

PmergeMe::PmergeMe(int argc, char *argv[]){
	//std::cout << "PmergeMe string array constructor called" << std::endl;
	this->johnsonFord(argc, argv);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::johnsonFord(int argc, char *argv[]){
	this->fill_containers(argc, argv);
	//start deque timer
	dequeSort();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << std::endl;
	
	
	//start vector time
	//_vector.vectorSort();
	//std::cout << "Time to process a range of" << argc - 1 << "elements with std::vector: " << std::endl;

}

void PmergeMe::dequeSort(){
	//std::deque<unsigned int>	holder;
	std::deque<std::set<unsigned int> >	holder;
	bool 		odd = false;
	//create a set of half the size of the (if it is not even then one extra element)
	//size_t set_size = _deque.size() / 2;
	if (_deque.size() % 2 != 0){
		//set_size++;
		odd = true;
	}
	// STEP ONE CREATE A SET of TWO and store in a pair> (THIS COMBINES PAIR AND ORDER (reverse order))
	//std::set<std::pair<set<int>, set<int>> myset;
	std::set<unsigned int> pairing;
	//for (size_t i = 1; i < _deque.size(); i+= 2){
	int count = 0;
	//for(std::deque<unsigned int>::iterator iter = _deque.begin(); iter != _deque.end(); ++iter){
	for (size_t i = 0; i < _deque.size(); i++){
	//++iter;
	 /* 	std::deque<unsigned int>::iterator t = iter;
		t++;
		if (t == _deque.end())
			break ; */
		pairing.insert(_deque[i]);
		count++;
		if (count == 2)
		{
			holder.push_back(pairing);
			pairing.clear();
			count = 0;
		}
		/* pairing.insert(iter, t);
		pairing.insert(&_deque[i - 1], &_deque[i]);
		holder.push_back(pairing);
		pairing.clear(); */
		//std::pair<int, int> p = std::make_pair()
		//myset = 
		//std::pair<int, int> p = std::make_pair(_deque[i - 1], _deque[i]);
	}
	if (odd == true){
		pairing.insert(_deque.back());
		holder.push_back(pairing);
	}

	for (size_t j = 0; j < holder.size(); j++){
		//std::set<unsigned int>::iterator it = holder[j].begin();
		for (std::set<unsigned int>::iterator it = holder[j].begin(); it != holder[j].end(); ++it)
    		std::cout << *it << " ";
		std::cout << ", ";
	}
	/* for (std::deque<std::set<int> >::iterator h_it = _deque.begin(); h_it != _deque.end(); ++h_it){
		for (std::set<int>::iterator it = *h_it->begin(); it != *h_it->end(); ++it)
    		std::cout << *it << " ";
		std::cout << ", ";
	} */
	std::cout << std::endl;
}
/* void PmergeMe::dequeSort(){
	std::deque<unsigned int>	holder;
	bool 		odd = false;
	//create a set of half the size of the (if it is not even then one extra element)
	//size_t set_size = _deque.size() / 2;
	if (_deque.size() % 2 != 0){
		//set_size++;
		odd = true;
	}
	std::set<std::pair<int, int> > s;
	for (size_t i = 1; i < _deque.size(); i+= 2){
		std::pair<int, int> p = std::make_pair(_deque[i - 1], _deque[i]);
		s.insert(p);
	}
	if (odd == true)
		holder.push_back(_deque.back());
	for (std::set<std::pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it)
    	std::cout << it->first << " " << it->second << ", ";
	std::cout << std::endl;
} */

void PmergeMe::fill_containers(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string temp = argv[i];
		//std::cout << "argc: " << i  << "char: " << argv[i] << std::endl;
		//std::cout << "argc: " << i  << "char: " << temp << std::endl;
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
		if (n < 0 || n > INT_MAX) //dont think i need negative check as it should fault on the minus // should be unsinged int max
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
	//Start timer
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