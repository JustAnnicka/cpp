/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:04:03 by aehrl             #+#    #+#             */
/*   Updated: 2025/09/21 19:30:07 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "default";
}
Weapon::Weapon(const std::string &type):type(type)
{
	//std::cout << "Desctructor" << std::endl;
}
Weapon::~Weapon()
{
//	std::cout << "Desctructor" << std::endl;
}
std::string Weapon::getType()
{
	return(this->type);
}
void Weapon::setType(std::string const &type)
{
	this->type = type;
}

	
