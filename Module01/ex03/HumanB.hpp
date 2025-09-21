/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:10:50 by aehrl             #+#    #+#             */
/*   Updated: 2025/09/20 16:18:34 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
 #define HUMANB_HPP

 #include "Weapon.hpp"
 
 class HumanB
 {
	std::string	name;
	Weapon		weapon;
	public:
		void attack();
		void setWeapon(Weapon set_weapon);
		HumanB();
		HumanB(std::string name);
		~HumanB();
 };

#endif