#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

 #include <stack>
 #include <iterator>

template <typename T>
class MutantStack : public std::stack<T>  {

	//std::iterator<T> it;
	public:
		MutantStack(): std::stack<T>(){
			std::cout << "MutantStack constructor called" << std::endl;
		};
		MutantStack(const MutantStack& other) : std::stack<T>(other){
			std::cout << "MutantStack copy constructor called" << std::endl;
		};
		MutantStack & operator=(const MutantStack & other){
			std::cout << "MutantStack copy assignment operator called" << std::endl;
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		};
		~MutantStack(){
			std::cout << "MutantStack destructor called" << std::endl;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){return (this->c.begin());};
		iterator end(){return (this->c.end());};
		//use c_begin to get iterator begin
		

};

#endif