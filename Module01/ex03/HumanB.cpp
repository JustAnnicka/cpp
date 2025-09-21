/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:04:00 by aehrl             #+#    #+#             */
/*   Updated: 2025/09/21 19:29:55 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	name = "HumanB";
}
HumanB::HumanB(std::string name) 
{
	this->name = name;
}

HumanB::~HumanB()
{
	//std::cout << this->name << "Destroyed" << std::endl;
}
void	HumanB::setWeapon(Weapon set_weapon)
{
	this->weapon = set_weapon; 
}
void	HumanB::attack()
{
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}