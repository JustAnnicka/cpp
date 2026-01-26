/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/26 18:09:54 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    if (this != &other) {
        *this = other;
        // No info to copy
    }
    return *this;
}
Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}


AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[] = {"shrubbery creation request", "robotomy request", "presidential pardon request"};
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            switch (i)
            {
                case 0:
                {
                    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                    return(new ShrubberyCreationForm(target));
                }
                case 1:
                {
                    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                    return(new RobotomyRequestForm(target));
                }
                case 2:
                {
                    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                    return(new PresidentialPardonForm(target));
                }
            }

        }
    }
    std::cout << "Intern Error: Error with " << name << std::endl;
    throw FormNotFoundException();
    return (NULL);

}

const char *Intern::FormNotFoundException::what() const throw(){
    return ("Intern Exception: Not a valid form\n");
}

