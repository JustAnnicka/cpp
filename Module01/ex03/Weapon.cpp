/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:04:03 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/10 20:35:53 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	_type = "default";
	std::cout << "Default constructor called" << std::endl;

}
Weapon::Weapon(const std::string &type):_type(type){}

Weapon::~Weapon()
{
	//std::cout << "Weapon Destructor called" << std::endl;
}
std::string Weapon::getType()
{
	return(this->_type);
}
void Weapon::setType(std::string const &type)
{
	this->_type = type;
}

	
