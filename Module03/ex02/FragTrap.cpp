/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/15 18:56:08 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "FragDefault";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap string constructor called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (this->energy_points > 0 && this->hit_points > 0)
        std::cout << this->name << ": You look fly would you like to High-Five?" << std::endl;
    else if (this->hit_points <= 0)
        std::cout << this->name << " is dead and cannot high-five" << std::endl;
    else
        std::cout << this->name << " is to tired to high-five" << std::endl;
}
