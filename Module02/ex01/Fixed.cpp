/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/12 16:45:22 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->nbr_v = 0;
}

Fixed::Fixed(const int param) {
    std::cout << "Int constructor called" << std::endl;
    this->nbr_v = param << this->bits;
    //this->nbr_v = param;
}

Fixed::Fixed(const float param) {
    std::cout << "Float constructor called" << std::endl;
    int scale = 1 << this->bits;
    this->nbr_v = static_cast<int>(roundf(param * scale));
}

Fixed::Fixed(const Fixed &ptr) {
    std::cout << "Copy constructor called" << std::endl;
    *this = ptr;
}

Fixed &Fixed::operator=(const Fixed &ptr) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ptr) {
      this->nbr_v = ptr.getRawBits();
    //    this->nbr_v = ptr.nbr_v;
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->nbr_v);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->nbr_v = raw;
}

float Fixed::toFloat() const
{
    float ret;
	int	scale = 1 << this->bits;
	ret = (float)this->nbr_v/ (float)scale;
	return (ret);
}
int Fixed::toInt() const
{
  	int ret;
	ret = this->nbr_v >> this->bits;
	return (ret);
}



std::ostream& operator<<(std::ostream &os, const Fixed &ptr){
	os << ptr.toFloat();
	return (os);
}

/* An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter. */