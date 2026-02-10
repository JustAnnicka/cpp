
#include "Span.hpp"

Span::Span() : _max_elements(0){
	_is_sorted = false;
}

Span::Span(unsigned int N) : _max_elements(N){
	std::cout << "Span unsigned int constructor called" << std::endl;
	_is_sorted = false;
	if (N >= _myvector.max_size() || N == 0)
		throw(ConstructSpanFailed());
	_myvector.reserve(N);
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
	if (size > _max_elements)
		throw(RangeNotValid());
	_myvector.insert(_myvector.end(), first, last);
	_is_sorted = false;
	//std::cout << "Size" << _myvector.size() << std::endl;
}


unsigned int Span::shortestSpan(){
	
	if (_myvector.size() <= 1)
		throw (NoSpanFound());
	if (_is_sorted == false)
	{
		std::sort(_myvector.begin(), _myvector.end());
		_is_sorted = true;
	}
	unsigned int s_span = 0;
	unsigned int x;
	std::vector<int>::iterator t_it = _myvector.begin();
	for (std::vector<int>::reverse_iterator it = _myvector.rbegin() ; it != _myvector.rend(); ++it)
	{
		t_it++;
		x = abs(*it - *t_it);
		if (x != 0 && (x < s_span || s_span == 0))
		{
			s_span = x;
			//std::cout << "it: " << *it << " t_it: " << *t_it << " span: " << s_span << std::endl;
		}
	}
	return (s_span);
}

unsigned int Span::longestSpan(){
	int min_v;
	int max_v;
	if (_myvector.size() <= 1)
		throw (NoSpanFound());
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