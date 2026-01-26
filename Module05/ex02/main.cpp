/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/26 15:38:53 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "=== Program Bureaucrat started ===" << std::endl;
    std::string test = "trees";
    Bureaucrat      bureaucratA;
    Bureaucrat      bureaucratB("B", 5);
    Bureaucrat      bureaucratC("C", 150);
    AForm*    formS = new ShrubberyCreationForm(test);
    AForm*    formR = new RobotomyRequestForm();
    AForm*    formP = new PresidentialPardonForm("Jimmy");


    std::cout << "\n=== Bureaucrat & Form information ===" << std::endl;
	std::cout << bureaucratA;
    std::cout << *formS;
    std::cout << *formR;
    std::cout << *formP;
    std::cout << "\n=== Attempt to Sign ===" << std::endl;
    bureaucratC.signForm(*formS);
    std::cout << *formS;
    bureaucratA.signForm(*formR);
    std::cout << *formR;
    bureaucratA.signForm(*formP);
    std::cout << *formP;
    std::cout << "\n=== Attempt to Excecute ===" << std::endl;
    bureaucratA.executeForm(*formS);
    bureaucratB.executeForm(*formR);
    bureaucratC.executeForm(*formP);
   std::cout << "\n=== Actually Sign Forms ===" << std::endl;
   bureaucratA.signForm(*formS);
   std::cout << *formS;
   bureaucratB.signForm(*formR);
   std::cout << *formR;
   bureaucratB.signForm(*formP);
   std::cout << *formP;
   std::cout << "\n=== Attempt to Excecute ===" << std::endl;
   bureaucratA.executeForm(*formS);
  // std::cout << *formS;
   bureaucratB.executeForm(*formR);
  // std::cout << *formR;
   bureaucratC.executeForm(*formP);
   bureaucratB.executeForm(*formP);
  // std::cout << *formP;
   
    std::cout << "\n=== Program Bureaucrat ended ===" << std::endl;
    delete formS;
    delete formR;
    delete formP;
    return 0;
}
