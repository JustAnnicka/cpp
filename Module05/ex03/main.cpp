/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/26 18:20:47 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main() {
    std::cout << "=== Program Bureaucrat started ===" << std::endl;


    Intern someRandomIntern;
    AForm* rrf = NULL;
    AForm* srf = NULL;
    AForm* ppf = NULL;
    AForm* ppf2 = NULL;
    
    try{
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf;
        srf = someRandomIntern.makeForm("shrubbery creation request", "Twigs");
        std::cout << *srf;
        ppf = someRandomIntern.makeForm("presidential pardon request", "Phill");
        std::cout << *ppf;
        ppf2 = someRandomIntern.makeForm("presidential pardon", "Diddy");
        std::cout << ppf2->getName();
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
   
    
    std::cout << "\n=== Program Bureaucrat ended ===" << std::endl;
    if (rrf != NULL)
        delete rrf;
    if (srf != NULL)
        delete srf;
    if (ppf != NULL)
        delete ppf;
    if (ppf2 != NULL)
        delete ppf;
    return 0;
}
