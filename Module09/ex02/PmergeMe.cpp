
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
	_tracker = 0;
	//std::cout << "PmergeMe constructor called" << std::endl;
	//do i have to init time to NULL?

}

PmergeMe::PmergeMe(int argc, char *argv[]){
	_tracker = 0;
	//std::cout << "PmergeMe string array constructor called" << std::endl;
	this->johnsonFord(argc, argv);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::johnsonFord(int argc, char *argv[]){
	_tracker = 0;
	this->fill_containers(argc, argv);
	//start deque timer
	dequeSort(_deque);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << std::endl;
	
	
	//start vector time
	//_vector.vectorSort();
	//std::cout << "Time to process a range of" << argc - 1 << "elements with std::vector: " << std::endl;

}
//we could in theory make both of these templates for deque and vector (maybe deque can push front using other function for insertion)
int PmergeMe::JacobThal(size_t n){
	//We are skipping 0 & 1 as we they are the value we need
	int Jn;
	int x;
	if (n <= 2)
		return (1);
	Jn = JacobThal(n - 1); 
	x = Jn + 2 * (JacobThal(n - 2));
	return (x);
}

std::deque<int> PmergeMe::JacobThalSequence(size_t n){
	//We are skipping 0 & 1 as we they are the value we need
	int Jn;
	size_t i = 1;
	std::deque<int> JTSequence;
	while (i++ < n && JTSequence.size() < n){
		Jn = JacobThal(i);
		if (Jn <= (int)n) 
			JTSequence.push_back(Jn);
		else
			JTSequence.push_back(n);
		//std::cout << "Jn: " << Jn << std::endl;
		if (i >= 3 && JTSequence.size() < n){
			Jn = *JTSequence.rbegin();
			JTSequence.push_back(Jn - 1);
		}
		//NEED SOMETHING TO BREAK IF THE RETURNED VALUE IS HIGHER THAN WHAT WE HAVE (PUSH N )
		// IF SIZE IS LOWER THEN DO DIFFERENCE AGAIN?
	}
	/* for (size_t j = 0; j <JTSequence.size(); j++)
			std::cout <<JTSequence[j] << ", "; */
	return (JTSequence);
}

std::deque<unsigned int> PmergeMe::pairing(std::deque<unsigned int> aux){
	std::deque<t_pairs> holder;
	if (aux.size() <= 1){
		return (aux);
	}
	std::deque<unsigned int> max_chain; 
	std::deque<unsigned int> min_chain; 
	static int recur;
	recur++;
	size_t size = aux.size() / 2;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux.front();
		aux.pop_front();	
		t_pairs p(x, aux.front());
		p.id = recur;
		//_dsort.push_back(p);
		holder.push_back(p);
		aux.pop_front();
		max_chain.push_back(p.max);
		min_chain.push_back(p.min);
	}
	//JUST FOR PRINTING PURPOSES
	std::cout << "Pairing #"<< recur << std::endl;
	/* for (size_t j = 0; j < _dsort.size(); j++){
		std::cout << _dsort[j].min << " " << _dsort[j].max << ", ";
	} */
	
	if (!aux.empty())
	{
		if (recur != 1)
			max_chain.push_back(aux[0]);
		std::cout << "r => ";
		for (size_t z = 0; z < aux.size(); z++){
			std::cout << aux[0] << ", ";
		}
	}
	std::cout << std::endl;
	for (size_t j = 0; j < max_chain.size(); j++)
		std::cout << max_chain[j] << ", ";
	std::cout << std::endl;
	for (size_t j = 0; j < min_chain.size(); j++)
		std::cout << min_chain[j] << ", ";
	std::cout << std::endl;
	max_chain = pairing(max_chain);
	
	//APPLY MIN CHECK SORT THROUGH BINARY SEARCH & JACOBTHAL NUMBER
	
	if (min_chain.size() == 1)
		max_chain.push_front(min_chain[0]);
	else{
		std::cout << "JacobThal of " << min_chain.size() << " is: ";
		std::deque<int> x = JacobThalSequence(min_chain.size());
		for (size_t j = 0; j <x.size(); j++)
			std::cout <<x[j] << ", ";
		 std::cout << std::endl;


		//BINARY SEARCH
		//Each pending value has a restricted search boundary (up to its paired max).
		// EG 83 will not look further than 99 (its paired max);
	}

	std::cout << "Returning: ";
	for (size_t i = 0; i < max_chain.size(); i++)
		std::cout << max_chain[i] << " ";
	std::cout << std::endl;

	recur--;
	return (max_chain);

}

void PmergeMe::dequeSort(std::deque<unsigned int> aux){
	std::deque<unsigned int> max_chain; 
	max_chain = pairing(aux);
	std::cout << "Sorted: " ;
	for (size_t j = 0; j < max_chain.size(); j++)
		std::cout << max_chain[j] << ", ";
	std::cout << std::endl;

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