/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/19 19:20:05 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat Default constructor called" << std::endl;
    this->_brain = new Brain();
    _type = "Cat";
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat Copy constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain); 
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
    delete this->_brain;
}


void Cat::makeSound(void) const{
	std::cout << this->_type << ": Miau..." << std::endl;
}