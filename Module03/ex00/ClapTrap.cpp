/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/15 19:20:36 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "Default constructor called" << std::endl;
    this->name = "Default";
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}
ClapTrap::ClapTrap(std::string name) {
    std::cout << "String constructor called" << std::endl;
    this->name = name;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (energy_points <= 0)
    {
        std::cout << "ClapTrap " << name << " tries to attack but has no energy" << std::endl;
        return ;
    }
    else if (hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points left and cannot attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
    energy_points--;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points left" << std::endl;
        return ;
    }
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points <= 0)
    {
        std::cout << "ClapTrap " << name << " tries to repair but has no energy" << std::endl;
        return ;
    }
    else if (hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points left and cannot repair" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " repairs " << amount << " hit points" << std::endl;
    energy_points--;
    hit_points += amount;
}
