/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:03:55 by aehrl             #+#    #+#             */
/*   Updated: 2025/09/21 19:30:00 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
	name = "HumanA";
	//Weapon::setType("random Weapon");
}
HumanA::HumanA(std::string name, Weapon weapon) //: {name(name), weapon(weapon);}// can do that with member init :
{
	this->name = name;
	this->weapon = weapon;
}
HumanA::~HumanA()
{
//	std::cout << this->name << "Destroyed" << std::endl;
}
void HumanA::attack()
{
	std::cout << name << " attacks with their " << this->weapon.getType()<< std::endl;
}