/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/15 19:36:37 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(){
    std::cout << "Diamond default constructor called" << std::endl;
    name = "(null)";
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
   
    std::cout << "Diamond string constructor called" << std::endl;
    this->name = name;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other; //test this
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    if (this->energy_points > 0 && this->hit_points >  0)
        std::cout << "My ClapTrap name is " << ClapTrap::name << "\n" << this->name << " is who I am!" << std::endl;
    else if (hit_points <=  0)
        std::cout << this->name << " " << ClapTrap::name << " is dead!" << std::endl;
    else
        std::cout << this->name << " " << ClapTrap::name << " is out of energy!" << std::endl;
}
