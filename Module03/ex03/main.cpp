/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/22 19:01:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main() {
    ClapTrap claptrap("Dude");
    DiamondTrap diamondtrap("Diamond");
    DiamondTrap second_diamond;
  //  DiamondTrap diamondtrap("Diamond");
    
    claptrap.attack("Savy");
    diamondtrap.takeDamage(0);
    diamondtrap.attack("Dude");
    claptrap.takeDamage(30);
    claptrap.beRepaired(10);
    second_diamond.highFivesGuys();
    diamondtrap.highFivesGuys();
    diamondtrap.attack("null");
    second_diamond.takeDamage(30);
    second_diamond.attack("Diamond");
    diamondtrap.takeDamage(30);
    diamondtrap.guardGate();
    diamondtrap.whoAmI();
    second_diamond.whoAmI();
    return 0;
}
