/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:10:50 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/05 18:13:03 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
 #define HUMANA_HPP

 #include "Weapon.hpp"
 
 class HumanA
 {
	std::string	_name;
	Weapon		&_weapon;
	public:
		void attack();
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
 };

#endif