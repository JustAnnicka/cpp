/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:29:54 by aehrl             #+#    #+#             */
/*   Updated: 2025/08/21 17:33:28 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>//do i neew this i think not
#include <string>

class	Zombie
{
	private:
		std::string	name;
	public:
		void	announce(void); //should be a member function?
		void	set_name(std::string name);
		Zombie();
		Zombie(const std::string name);
		//I should make a copy function//

		~Zombie();
	
};

Zombie* zombieHorde(int N, std::string name);

#endif
