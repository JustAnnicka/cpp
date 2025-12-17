/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/22 17:35:22 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {
    ClapTrap claptrap("Dude");
    ScavTrap scavtrap("Savy");
    FragTrap fragtrap("Guy");
    
    claptrap.attack("Savy");
    scavtrap.takeDamage(0);
    scavtrap.attack("Dude");
    claptrap.takeDamage(20);
    claptrap.beRepaired(10);
    fragtrap.highFivesGuys();
    scavtrap.attack("Guy");
    fragtrap.takeDamage(20);
    fragtrap.attack("Savy");
    scavtrap.takeDamage(30);
    scavtrap.guardGate();
    return 0;
}
