/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/22 17:25:33 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {
    ClapTrap claptrap("Dude");
    ScavTrap scavtrap("Savy");
    
    claptrap.attack("Savy");
    scavtrap.takeDamage(0);
    scavtrap.attack("Dude");
    claptrap.takeDamage(20);
    claptrap.beRepaired(10);
    scavtrap.attack("Dude");
    claptrap.takeDamage(20);
    scavtrap.guardGate();
    return 0;
}
