/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:04:00 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/10 20:22:19 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "HumanB";
	_weapon = NULL;
}
HumanB::HumanB(std::string name) 
{
	this->_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
//	std::cout << this->_name << " Destroyed" << std::endl;
}
void	HumanB::setWeapon(Weapon &set_weapon)
{
	_weapon = &set_weapon;
}
void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attak with " << std::endl;
}