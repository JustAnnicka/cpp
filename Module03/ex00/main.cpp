/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/17 20:18:44 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/* int main() {
    ClapTrap claptrap("Dude");
    
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.beRepaired(10);
    claptrap.attack("Enemy");


    return 0;
} */
int main() {
    ClapTrap claptrap("Dude");
    
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.attack("Enemy");
    claptrap.takeDamage(9);
    claptrap.beRepaired(10);
    claptrap.attack("Enemy");
    claptrap.takeDamage(13);
    claptrap.attack("Enemy");



    return 0;
}
