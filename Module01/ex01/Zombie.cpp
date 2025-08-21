/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:29:58 by aehrl             #+#    #+#             */
/*   Updated: 2025/08/21 17:34:36 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){name = "random";}
Zombie::~Zombie()
{
	std::cout << "destroyed " << name << std::endl;
	//should I add the destroy function here?
}

Zombie::Zombie(const std::string name) : name(name){}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
void	Zombie::set_name(std::string name)
{
	this->name = name;
}