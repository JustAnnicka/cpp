/* template <typename T> 
T& Array<T>::operator[](){
	std::cout << "Array constructor called" << std::endl;
	_array = new T[1];
	_array[1] = NULL;
} */
#include <climits>

template <typename T>
Array<T>::Array(){
	std::cout << "Array constructor called" << std::endl;
	_array = new T[0];
	_s = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
	std::cout << "Array unsigned int constructor called" << std::endl;
	//will it not just try to set it as a pos once passed here
	if (n < 0 || n > ULONG_MAX)//max of unsigned int
		throw (OutOfRangeException());
	// also minimum size 1
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();
	_s = n;
	//initialised by default (IE I SHOULD ADD CONTENT FOR EACH ELEMENT??)
	
}

template<typename T>
Array<T>::~Array(){
	std::cout << "Arrray destructor called" << std::endl;
	delete[] _array;
}	

template <typename T>
Array<T>::Array(const Array<T> & other){
	std::cout << "Deep copy constructor called" << std::endl;
	unsigned int size = other.size();
	this->_array = new T[size];
	_s = size;
	for (unsigned int i = 0; i < size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other){
	std::cout << "Deep copy constructor assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._s];
		_s = other._s;
		for (unsigned int i = 0; i < _s; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T & Array<T>::operator[](long long n){
	if (n < 0 || n >= this->size())
		throw (OutOfRangeException());
	return (_array[n]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	//std::cout << sizeof(&_array) / sizeof(&_array[0]) << std::endl;
	//In theory this should return the size of the array
	return (_s);
}



// Also how do I return the value of the Array at [n] when called directly as Array[]
//how do i throw expetion if someone ties to acces the values