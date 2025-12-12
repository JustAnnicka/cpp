/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/12 19:09:55 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
     //std::cout << "Default constructor called" << std::endl;
    this->_nbr_v = 0;
}

Fixed::Fixed(const int param) {
     //std::cout << "Int constructor called" << std::endl;
    this->_nbr_v = param << this->bits;
}

Fixed::Fixed(const float param) {
     //std::cout << "Float constructor called" << std::endl;
    int scale = 1 << this->bits;
    this->_nbr_v = static_cast<int>(roundf(param * scale));
}

Fixed::Fixed(const Fixed &ptr) {
     //std::cout << "Copy constructor called" << std::endl;
    *this = ptr;
}

Fixed &Fixed::operator=(const Fixed &ptr) {
     //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ptr)
      this->_nbr_v = ptr.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
     //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	 //std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr_v);
}

void Fixed::setRawBits(int const raw)
{
	 //std::cout << "setRawBits member function called" << std::endl;
	this->_nbr_v = raw;
}

float Fixed::toFloat() const
{
    float ret;
	int	scale = 1 << this->bits;
	ret = (float)this->_nbr_v/ (float)scale;
	return (ret);
}

int Fixed::toInt() const
{
  	int ret;
	ret = this->_nbr_v >> this->bits;
	return (ret);
}

/* An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter. */

std::ostream& operator<<(std::ostream &os, const Fixed &ptr){
	os << ptr.toFloat();
	return (os);
}

bool Fixed::operator<(const Fixed& toCompare) const{return(this->_nbr_v < toCompare.getRawBits());}
bool Fixed::operator>(const Fixed& toCompare) const{return(this->_nbr_v > toCompare.getRawBits());}
bool Fixed::operator>=(const Fixed& toCompare) const{return(this->_nbr_v >= toCompare.getRawBits());}
bool Fixed::operator<=(const Fixed& toCompare) const{return(this->_nbr_v <= toCompare.getRawBits());}
bool Fixed::operator==(const Fixed& toCompare) const{return(this->_nbr_v == toCompare.getRawBits());}
bool Fixed::operator!=(const Fixed& toCompare) const{return(this->_nbr_v != toCompare.getRawBits());}

Fixed Fixed::operator++(){this->_nbr_v++; return (*this);}
Fixed Fixed::operator--(){this->_nbr_v--; return (*this);}
Fixed Fixed::operator++(int ){
    Fixed   oldValue = *this; 
    this->_nbr_v++;
    return (oldValue);
}
Fixed Fixed::operator--(int){
    Fixed   oldValue = *this; 
    this->_nbr_v--;
    return (oldValue);
}

// Function based on the actual description of POST INCREMENT/DECREMENT
// int value can be changed by calling  a.operator++(2) or operator++(a, 2)
/* Fixed Fixed::operator++(int x){
    Fixed   oldValue = *this; 
    _nbr_v += x; //might not be allowed in the actual subject
    return (oldValue)
}
Fixed Fixed::operator--(int x){
     Fixed   oldValue = *this; 
    _nbr_v += x; //might not be allowed in the actual subject
    return (oldValue)
}
 */

Fixed Fixed::operator+(const Fixed& toAdd) const {return(Fixed(this->toFloat() + toAdd.toFloat()));}
Fixed Fixed::operator-(const Fixed& toAdd) const {return(Fixed(this->toFloat() - toAdd.toFloat()));}
Fixed Fixed::operator*(const Fixed& toAdd) const {return(Fixed(this->toFloat() * toAdd.toFloat()));}
Fixed Fixed::operator/(const Fixed& toAdd) const {return(Fixed(this->toFloat() / toAdd.toFloat()));}
Fixed& Fixed::min(Fixed& v1, Fixed& v2){
    if (v1 < v2)
        return(v1);
    return (v2);
}

const Fixed& Fixed::min(const Fixed& v1, const Fixed& v2){
    if (const_cast<Fixed&>(v1) < v2)
        return(v1);
    return (v2);
}

Fixed& Fixed::max(Fixed& v1, Fixed& v2){
    if (v1 > v2)
        return(v1);
    return (v2) ;
}

const Fixed& Fixed::max(const Fixed& v1, const Fixed& v2){
    if (const_cast<Fixed&>(v1) > v2)
        return(v1);
    return (v2) ;
}