/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:29:58 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/10 20:08:46 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){_name = "random";}
Zombie::~Zombie()
{
	std::cout << "destroyed " << _name << std::endl;
}

Zombie::Zombie(const std::string name) : _name(name){}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
void	Zombie::set_name(std::string name)
{
	this->_name = name;
}