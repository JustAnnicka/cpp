/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:29:54 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/10 20:08:35 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		void	announce(void);
		void	set_name(std::string name);
		Zombie();
		Zombie(const std::string name);
		~Zombie();
	
};

Zombie* zombieHorde(int N, std::string name);

#endif
