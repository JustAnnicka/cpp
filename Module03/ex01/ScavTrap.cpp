/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/15 18:53:24 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "Scav Trap default constructor called" << std::endl;
    this->name = "ScavDefault";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "Scav Trap string constructor called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; //test this
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(){
    if (this->energy_points > 0 && this->hit_points > 0)
        std::cout << this->name << " is now in guard mode" << std::endl;
    else
        std::cout << this->name << " Is either low on energy or health" << std::endl;
}
