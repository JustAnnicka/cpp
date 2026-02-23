
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
	dequeSort(_deque);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << std::endl;
	
	
	//start vector time
	//_vector.vectorSort();
	//std::cout << "Time to process a range of" << argc - 1 << "elements with std::vector: " << std::endl;

}

//Use a template for the pairs

//Make pairs functions -> make a pair from a deque and then push to holder
//template <typename T>  std::list<T> make_pairs_deque(T container){
/* template <typename T>  void creating_pairs(T container){
	T<T> holder;
	std::pair
	bool odd = false;
	size_t size = container.size() / 2;
	static int count; //just for me to visualise the the count (delete this later)
	if (container.size() % 2 != 0)
	{
		odd = true;
		size++;
	}
	//std::pair<T> pair;
	for (size_t i = 0; i < size; i++){

		holder.push(container.back());
		container.pop_back();
		holder.push(container.back());
		container.pop_back();
	} 
} */
//sort pair functions

template <typename T> bool first_is_bigger(T a, T b){

	//if (typeid(a->second) != typeid(std::pair<std::deque<unsigned int>, std::deque<unsigned int>))
	//if (typeid(a->second) != typeid(std::pair<unsigned int, unsigned int>))
	if (typeid(a) == typeid(unsigned int))
		return(a > b);
	return (a>b);
	/* else if (typeid(a->second) != typeid(std::pair<unsigned int, unsigned int>))
		return (sort_pairs(a->second, b->second));
	else
		return (a->second > b->second); */

	
		// by comparing the second I should auto know if I am one away from pair
	// Maybe what makes more sense is to 
	/* if (typeid(*T) == type(std::deque)){
		for (T::iterator it = container.begin(); it != s.end(); ++it)
		{
			if (typeid(container->first) != typeid(std::pair<std::deque<unsigned int>, std::deque<unsigned int>))

		}


	} */

}

/* for (size_t i = 0; i < size; i++){
		one.push_back(aux.front());
		aux.pop_front();
		two.push_back(aux.front());
		aux.pop_front();
		pairing = make_pair(one, two);
		holder.push_back(pairing);
	} */


void PmergeMe::dequeSort(std::deque<unsigned int> aux){
	std::pair<unsigned int, unsigned int> pairing;
	std::deque<std::pair<unsigned int, unsigned int> > holder;
	//std::deque<std::pair<std::deque<unsigned int>, std::deque<unsigned int> > > holder;
	//std::deque<unsigned int> one;
	//std::deque<unsigned int> two;
	size_t size = aux.size() / 2;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux.front();
		aux.pop_front();
		pairing = std::make_pair(x, aux.front());
		aux.pop_front();
		holder.push_back(pairing);
	}
	std::cout << "Pairing #1" << std::endl;
	for (size_t j = 0; j < holder.size(); j++){
		std::cout << holder[j].first << " " << holder[j].second << ", ";
	}
	if (!aux.empty())
	{
		std::cout << "r => ";
		for (size_t z = 0; z < aux.size(); z++){
			std::cout << aux[0] << ", ";
		}
	}
	std::cout << std::endl;
	for (size_t z = 0; z < holder.size(); z++){
		if (first_is_bigger(holder[z].first, holder[z].second))
		{
			unsigned int n = holder[z].first;
			holder[z].first = holder[z].second;
			holder[z].second = n;
			//std::deque<std::pair<unsigned int, unsigned int> temp = holder[z]
		}
		std::cout << holder[z].first << " " << holder[z].second << ", ";
	}
	std::cout << std::endl;
	//sort_pairs(&holder);
}

/* void PmergeMe::MakePairs(std::deque<std::set<unsigned int> > container){
	std::deque<std::pair<std::set<unsigned int>, std::set<unsigned int> > >holder;
	//std::deque<std::set<std::pair<std::set<unsigned int> >> holder;
	//std::set<std::pair<std::set<unsigned int> >> set;
	std::pair<std::set<unsigned int>, std::set<unsigned int> > pairs;
	size_t size = container.size();
	bool 		odd = false;
	if (size % 2 != 0)
		odd = true;

	for (size_t i = 1; i < size; i++){
		if(*container[i-1].rbegin() < *container[i].rbegin())
			pairs = std::make_pair(container[i - 1], container[i]);
		else
			pairs = std::make_pair(container[i], container[i - 1]);
		holder.push_back(pairs);
		size_t x = i + 1;
		i = x;
	}
	for (size_t j = 0; j < holder.size(); j++){
		std::cout << holder[j].first << " " << holder[j].second << ", ";
	}
	std::cout << std::endl; */
/* 	if (odd == true){
		pairing.insert(container.back());
		holder.push_back(pairing);
	} */
//}

//create pairs -> do a type identify for the sorting. If the first / second is notn an unsigned int but a pair call function again. then return the result

//CREATE PAIR TEMPLATE FUNCTION THAT RETURNS DEQUE ENTRY



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