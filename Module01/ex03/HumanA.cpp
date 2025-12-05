/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:03:55 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/05 18:14:57 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _weapon(weapon){}

HumanA::~HumanA()
{
	//std::cout << this->_name << "Destroyed" << std::endl;
}
void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType()<< std::endl;
}