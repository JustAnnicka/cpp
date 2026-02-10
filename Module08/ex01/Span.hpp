
#ifndef SPAN_HPP
 #define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();

		void addNumber(int i);
		void multiAddNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
	class ConstructSpanFailed : public  std::exception{
		public:
			virtual const char* what() const throw();
	};
	class RangeNotValid : public  std::exception{
		public:
			virtual const char* what() const throw();
	};
	class MaxElementsReached : public  std::exception{
		public:
			virtual const char* what() const throw();
	};
	class NoSpanFound : public std::exception{
		public:
			virtual const char* what() const throw();
	};

	private:
		std::vector<int> _myvector;
		bool	_is_sorted;
		const unsigned int _max_elements;
};

#endif