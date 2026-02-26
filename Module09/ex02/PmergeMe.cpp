
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

std::deque<unsigned int> PmergeMe::recursive_pairing(std::deque<t_pairs> aux){
	std::deque<t_pairs> holder; 
	size_t size = aux.size() / 2;
	static int id;
	id++;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux[i].max;
		t_pairs p(x, aux[i + 1].max);
		p.id = id;
		holder.push_back(p);
		_dsort.push_back(p);
		aux.pop_front();
	}
	for(size_t z = 0; z < size; z++)
		aux.pop_front();
	//JUST FOR PRINTING PURPOSES
	std::cout << "Pairing #" << id << std::endl;
	for (size_t j = 0; j < holder.size(); j++){
		std::cout << holder[j].min << " " << holder[j].max << ", ";
	}
	if (!aux.empty())
	{
		std::cout << "r => ";
		for (size_t z = 0; z < aux.size(); z++){
			std::cout << aux[0].max << ", ";
		}
		holder.push_back(aux[0]);
	}
	std::cout << std::endl;
	//END OF PRINT
	std::deque<unsigned int> max_chain;
	if (holder.size() != 1){
		max_chain = recursive_pairing(holder);
		for (int z = (int)holder.size() - 1; z >= 0; z--){
			if (find(max_chain.begin(), max_chain.end(), holder[z].min) == max_chain.end())
				max_chain.push_front(holder[z].min);
		}
	}
	else{
		max_chain.push_front(holder[0].max); //this could be an insert function
		max_chain.push_front(holder[0].min);
	}
	return(max_chain);

}
/* 
std::deque<unsigned int> PmergeMe::recursive_pairing(std::deque<t_pairs> aux){
	std::deque<t_pairs> holder; 
	size_t size = aux.size() / 2;
	static int id;
	id++;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux[i].max;
		t_pairs p(x, aux[i + 1].max);
		p.id = id;
		holder.push_back(p);
		_dsort.push_back(p);
		aux.pop_front();
	}
	for(size_t z = 0; z < size; z++)
		aux.pop_front();
	//JUST FOR PRINTING PURPOSES
	std::cout << "Pairing #" << id << std::endl;
	for (size_t j = 0; j < holder.size(); j++){
		std::cout << holder[j].min << " " << holder[j].max << ", ";
	}
	if (!aux.empty())
	{
		std::cout << "r => ";
		for (size_t z = 0; z < aux.size(); z++){
			std::cout << aux[0].max << ", ";
		}
		holder.push_back(aux[0]);
	}
	std::cout << std::endl;
	//END OF PRINT
	std::deque<unsigned int> max_chain;
	if (holder.size() != 1){
		max_chain = recursive_pairing(holder);
		for (int z = (int)holder.size() - 1; z >= 0; z--){
			if (find(max_chain.begin(), max_chain.end(), holder[z].min) == max_chain.end())
				max_chain.push_front(holder[z].min);
		}
	}
	else{
		max_chain.push_front(holder[0].max); //this could be an insert function
		max_chain.push_front(holder[0].min);
	}
	return(max_chain);

}
 */
//use the johnsjohnThal number somewhere!!

std::deque<unsigned int> PmergeMe::pairing(std::deque<unsigned int> aux){
	std::deque<t_pairs> holder;
	if (aux.size() <= 1){
		return (aux);
	}
	std::deque<unsigned int> max_chain; 
	static int recur;
	recur++;
	size_t size = aux.size() / 2;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux.front();
		aux.pop_front();	
		t_pairs p(x, aux.front());
		p.id = recur;
		_dsort.push_back(p);
		holder.push_back(p);
		aux.pop_front();
		max_chain.push_back(p.max);
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
	//max_chain.clear();
/* 	std::deque<unsigned int> temp = pairing(max_chain); 
	//max_chain.push_back(p.min);
	for (size_t z = 0; z < temp.size(); z++){
		
		max_chain.push_back(temp[z]);
	} */
	//max_chain.clear();
	std::deque<unsigned int> temp = pairing(max_chain);
	max_chain.clear();
	max_chain = temp;
	if(recur > 1){
		for (size_t z = 0; z < holder.size(); z++){
				max_chain.push_front(holder[z].min);
		}
	}
	
	std::cout << "Returning: ";
	for (size_t i = 0; i < max_chain.size(); i++)
		std::cout << max_chain[i] << " ";
	std::cout << std::endl;

	recur--;
	//sorted_max_chain.push_back(max_chain[0]);
	return (max_chain);
	//END OF PRINT

}

/* std::deque<unsigned int> ford_johnson_max(std::deque<unsigned int> input)
{
    // Base case
    if (input.size() <= 1)
        return input;

    std::deque<t_pairs> pairs;
    std::deque<unsigned int> max_values;

    // Build pairs
    while (input.size() >= 2)
    {
        unsigned int a = input.front();
        input.pop_front();

        unsigned int b = input.front();
        input.pop_front();

        t_pairs p(a, b);
        pairs.push_back(p);
        max_values.push_back(p.max);
    }

    // Handle leftover
    if (!input.empty()){

        max_values.push_back(input.front());
	}

	std::cout << "Returning: ";
	for (size_t i = 0; i < max_values.size(); i++)
		std::cout << max_values[i] << " ";
	std::cout << std::endl;
    // Recursively sort max values
    return ford_johnson_max(max_values);
} */
/* void PmergeMe::pairing(std::deque<unsigned int> aux){
	//std::deque<t_pairs> holder;
	size_t size = aux.size() / 2;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux.front();
		aux.pop_front();
		t_pairs p(x, aux.front());
		p.id = 0;
		_dsort.push_back(p);
		aux.pop_front();
	}
	//JUST FOR PRINTING PURPOSES
	std::cout << "Pairing #0" << std::endl;
	for (size_t j = 0; j < _dsort.size(); j++){
		std::cout << _dsort[j].min << " " << _dsort[j].max << ", ";
	}
	if (!aux.empty())
	{
		std::cout << "r => ";
		for (size_t z = 0; z < aux.size(); z++){
			std::cout << aux[0] << ", ";
		}
	}
	std::cout << std::endl;
	//END OF PRINT

} */


void PmergeMe::insertion(){

//	std::deque<unsigned int> main;
	std::deque<unsigned int> chain;
	t_pairs top = _dsort.back();
	chain.push_front(top.max);
	chain.push_front(top.min);
	// I dont think i need to add the other id to the _dsort just the initial pairing
	//FIND MATCH OF MAX
	int i = (int)_dsort.size() - 2; // this is the previous from top layer
	while (i){
		if (top.max == _dsort[i].max)
		{
			chain.push_front(_dsort[i].min);
			break ;
		}
		i--;
	}
	i = (int)_dsort.size() - 2;
	while (i){
		if (top.min == _dsort[i].max)
		{
			chain.push_front(_dsort[i].min);
			break ;
		}
		i--;
	}
	for (size_t j = 0; j < chain.size(); j++){
		std::cout << chain[j] << ", ";
	}

}

void PmergeMe::dequeSort(std::deque<unsigned int> aux){
	std::deque<unsigned int> max_chain; 
	max_chain = pairing(aux);
	for (size_t j = 0; j < max_chain.size(); j++)
		std::cout << max_chain[j] << ", ";
	//max_chain = recursive_pairing(_dsort);
	/* for (size_t j = 0; j < max_chain.size(); j++){
		std::cout << max_chain[j] << ", ";
	}
	std::cout << std::endl;
	for (size_t z = 0; z < max_chain.size(); z++){
		for(size_t i = 0; i < _dsort.size() && _dsort[i].id == 0; i++)
		{
			if (_dsort[i].max == max_chain[z]){
				std::cout << _dsort[i].min << ", ";
				break ;
			}
		}
		
	}
		std::cout << std::endl; */
	//insertion();
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