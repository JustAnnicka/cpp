/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:10:50 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/05 18:13:29 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
 #define HUMANB_HPP

 #include "Weapon.hpp"
 
 class HumanB
 {
	std::string	_name;
	Weapon		*_weapon;
	public:
		void attack();
		void setWeapon(Weapon &set_weapon);
		HumanB();
		HumanB(std::string name);
		~HumanB();
 };

#endif