/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/19 19:19:12 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Default constructor called" << std::endl;
    this->_type = "Animal";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other) {
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType(void) const{
	return (this->_type);
}
void Animal::makeSound(void) const {
    std::cout <<  this->_type << ": Animal sound" << std::endl;
}