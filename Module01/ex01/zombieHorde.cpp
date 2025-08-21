/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:29:47 by aehrl             #+#    #+#             */
/*   Updated: 2025/08/21 17:34:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	//Zombie	horde[N];
	//s
	// 
	Zombie	*horde = new Zombie[N];
	int i = 0;
	(void)name;
	while(i < N)
	{
		//this.name = name;
		//Zombie *aux = new (std::nothrow) Zombie(name);
		//if (!aux)
		//	std::cout << "Error\nCreating new Zombie number" << i << "\n"; 
		horde[i].set_name(name);
		//horde[i].name = name;
		horde[i].announce();
		i++;
	}
	//Zombie	*pointer = horde;
	return (horde);
}