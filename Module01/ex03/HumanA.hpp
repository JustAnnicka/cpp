/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:10:50 by aehrl             #+#    #+#             */
/*   Updated: 2025/08/21 18:41:07 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
 #define HUMANA_HPP

 #include "Weapon.hpp"
 
 class HumanA
 {
	std::string	name;
	Weapon		weapon;
	public:
		void attack();
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();
 };

#endif