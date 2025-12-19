/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/19 19:20:05 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog default constructor called" << std::endl;
    this->_brain = new Brain();
    _type = "Dog";
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog copy constructor called" << std::endl;
      this->_brain = new Brain(*other._brain); //Deep copy
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain); 
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}


void Dog::makeSound(void) const{
	std::cout << this->_type << ": Woof!" << std::endl;
}