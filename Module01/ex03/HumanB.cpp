/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:04:00 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/05 18:21:58 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "HumanB";
}
HumanB::HumanB(std::string name) 
{
	this->_name = name;
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
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}