/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:04:03 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/05 18:04:04 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	_type = "default";
}
Weapon::Weapon(const std::string &type):_type(type){}

Weapon::~Weapon()
{
	//std::cout << this->_type<< " Destroyed" << std::endl;
}
std::string Weapon::getType()
{
	return(this->_type);
}
void Weapon::setType(std::string const &type)
{
	this->_type = type;
}

	
