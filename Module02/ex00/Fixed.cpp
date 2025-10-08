/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:32:38 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/04 14:16:45 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	nbr_v = 0;
	std::cout << "Default constructor called\n";
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &ptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

void Fixed::operator=(const Fixed &ptr)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->nbr_v = ptr.getRawBits();
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