
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

/* template <typename T> bool first_is_bigger(T *a, T *b){

	//if (typeid(a->second) != typeid(std::pair<std::deque<unsigned int>, std::deque<unsigned int>))
	//if (typeid(a->second) != typeid(std::pair<unsigned int, unsigned int>))

	if (typeid(a->second) != typeid(std::pair<unsigned int, unsigned int>))
		return (sort_pairs(a->second, b->second));
	else
		return (a->second > b->second);
} */

//
//template <typename T> void deque_iterate_pairing(T container){
	//std::deque<unsigned int>;
	
/* 	if (container.size() > 1){	
		std::cout << "Pairing #2" << std::endl;
		std::pair<T, T> pairing;
		std::deque<std::pair<T, T> > holder;
		size_t size = container.size() / 2;
		for (size_t i = 0; i < size; i++){
			typename T::iterator it = container.begin();
			//std::deque<std::pair<T, T> >  x = container.front();
			pairing = std::make_pair(it, it+1);
			container.pop_front();
			container.pop_front();
			holder.push_back(pairing);

			//PRINT
		//	std::cout << holder[i].first << ", " << holder[i].second.first << " | ";
			//std::cout << holder[i].second.first << ", " << holder[i].second.second << " | ";

		} */
	/* 	for (size_t j = 0; j < holder.size(); j++){

			if (first_is_bigger(holder[j].first, holder[j].second))
			{
				T ptr = holder[j].first;
				holder[j].first = holder[j].second;
				holder[j].second = ptr;
			}
		} */
//	}
//}

void PmergeMe::recursive_pairing(std::deque<t_pairs> aux){
	std::deque<t_pairs> holder; //might not need holder
	size_t size = aux.size() / 2;
	static int id;
	id++;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux[i].max;
		//aux.pop_front();
		t_pairs p(x, aux[i + 1].max);
		p.id = id;
		holder.push_back(p);
		_dsort.push_back(p);
		//i = i + 1;
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
	}
	std::cout << std::endl;
	//END OF PRINT

	if (holder.size() != 1){
		recursive_pairing(holder);
	}

/* 	if (holder.size() != 1)
	{
		recursive_pairing(holder);
		_dsort.push_back(aux[0].max);
		_dsort.push_back(aux[0].min);
	}
	else
	{
		for (size_t j = 0; j < holder.size(); j++){
			_dsort.push_back(holder[j].min);
	} */

	//could do insertion here with the deque
}

void PmergeMe::pairing(std::deque<unsigned int> aux){
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

}

/* void PmergeMe::insertion(){
	//INSERTION A (BIGGER)
	std::deque<unsigned int> main;
	int count = 0;
	for (int i = (int)_dsort.size() - 1; i >= 0; i--)
	{	
		std::cout << "ENTER size: " << _dsort.size() << " i : " << i << std::endl;
		int x = i;
		if (!main.empty())
		{
			while(i > 1 && _dsort[i].max != main[0])
				i--;
		}
		//if (count == 0)
			main.push_front(_dsort[i].max);
		//else
	//		main.push_front(_dsort[i].min); 
		while(i > 1 && (int)_dsort[i].id == _dsort[x].id)
			i--;
		count++;
	}
	for (size_t j = 0; j < main.size(); j++){
		std::cout << main[j] << " ";
	}
	std::cout << std::endl;
} */
/* void PmergeMe::insertion(){

	std::deque<unsigned int> main;
	int count = 0;
	for (int i = (int)_dsort.size() - 1; i >= 0; i--)
	{	
		int x = i;
		if (count == 0)
			main.push_front(_dsort[i].max);
		else{
			int z = 0;
			while (_dsort[z].id == 0)
			{
				if (_dsort[z].max == _dsort[i].max)
					{
						main.push_front(_dsort[z].min);
						break ;
					}
				z++;
			}
		}
		
		//else
	//		main.push_front(_dsort[i].min); 
		while(i > 1 && (int)_dsort[i].id == _dsort[x].id)
			i--;
		count++;
	}
	for (size_t j = 0; j < main.size(); j++){
		std::cout << main[j] << " ";
	}
	std::cout << std::endl;

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
	//could do for lower function?
	/* int count = 0;
	for (int i = (int)_dsort.size() - 1; i >= 0; i--)
	{	
		int x = i;
		if (count == 0)
			main.push_front(_dsort[i].max);
		else{
			int z = 0;
			while (_dsort[z].id == 0)
			{
				if (_dsort[z].max == _dsort[i].max)
					{
						main.push_front(_dsort[z].min);
						break ;
					}
				z++;
			}
		}
		
		//else
	//		main.push_front(_dsort[i].min); 
		while(i > 1 && (int)_dsort[i].id == _dsort[x].id)
			i--;
		count++;
	}
	for (size_t j = 0; j < main.size(); j++){
		std::cout << main[j] << " ";
	}
	std::cout << std::endl; */

}

void PmergeMe::dequeSort(std::deque<unsigned int> aux){
	pairing(aux);
	recursive_pairing(_dsort);
	insertion();
	//recursive_pairing(aux);
/* 	std::pair<unsigned int, unsigned int> pairing;
	std::deque<std::pair<unsigned int, unsigned int> > holder;
	size_t size = aux.size() / 2;
	for (size_t i = 0; i < size; i++){
		unsigned int x = aux.front();
		aux.pop_front();
		pairing = std::make_pair(x, aux.front());
		aux.pop_front();
		holder.push_back(pairing);
	}
	//START OF PRINT
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
	//END OF PRINT
	for (size_t z = 0; z < holder.size(); z++){
		if (first_is_bigger(holder[z].first, holder[z].second))
		{
			unsigned int n = holder[z].first;
			holder[z].first = holder[z].second;
			holder[z].second = n;
		}
		std::cout << holder[z].first << " " << holder[z].second << ", ";
	}
	std::cout << std::endl;
	deque_iterate_pairing(holder); */
}

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