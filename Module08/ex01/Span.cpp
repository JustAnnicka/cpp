
#include "Span.hpp"

Span::Span() : _max_elements(0){
	_is_sorted = false;
	//will resize to 0 or 1 so that only one element can be added
}

Span::Span(unsigned int N) : _max_elements(N){
	std::cout << "Span unsigned int constructor called" << std::endl;
	_is_sorted = false;
	//try{
		if (N >= _myvector.max_size())
			throw(ConstructSpanFailed());
		_myvector.reserve(N);

	//}
	//catch (std::exception &e)
	//	std::cout << e.what() << std::endll; 
	//try catch should be in main as it will still try to create the class 
}

Span::~Span(){
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int i){
	std::cout << "Add Number called" << std::endl;
	if (_myvector.size() == _max_elements){
		throw(MaxElementsReached());
	}
	_myvector.push_back(i);
	_is_sorted = false;
}

void Span::multiAddNumber(std::vector<int>::iterator first, std::vector<int>::iterator last){

	unsigned int size = std::distance(first, last) + _myvector.size();
	if (size >= _max_elements)
		throw(RangeNotValid());
	_myvector.insert(_myvector.end(), first, last);
	_is_sorted = false;
}
// should work with range of iterators


unsigned int Span::shortestSpan(){
	
	if (_myvector.size() <= 1)
		throw (NoSpanFound());
	if (_is_sorted == false)
	{
		std::sort(_myvector.begin(), _myvector.end());
		_is_sorted = true;
	}
	unsigned int s_span = 0;
	unsigned int x = 0;
	std::vector<int>::iterator t_it = _myvector.begin();
	for (std::vector<int>::reverse_iterator it = _myvector.rbegin() ; it != _myvector.rend(); ++it)
	{
		t_it++;
		x = abs(*it - *t_it);
		if (x < s_span || s_span == 0)
			s_span = x;
	}
	return (s_span);
}

unsigned int Span::longestSpan(){
	int min_v;
	int max_v;
	if (_myvector.size() <= 1)
		throw (NoSpanFound()); // could do a span is empty exception
	if(_is_sorted){
		min_v = *_myvector.begin();
		max_v = *_myvector.rbegin();
	}
	else{
		min_v = *std::min_element(_myvector.begin(), _myvector.end());
		max_v = *std::max_element(_myvector.begin(), _myvector.end());
	}
	if (max_v - min_v == 0)
		throw (NoSpanFound());
	return (max_v - min_v);
}

const char *Span::ConstructSpanFailed::what() const throw(){
	return ("Construction of span failed.");
}

const char *Span::RangeNotValid::what() const throw(){
	return ("Error\nRange will exceed max number of elements.");
}
const char *Span::MaxElementsReached::what() const throw(){
	return ("Maximum elements reached. Can't add more");
}

const char *Span::NoSpanFound::what() const throw(){
	return ("No span found.");
}