/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/25 18:11:39 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Program Bureaucrat started ===" << std::endl;
    Bureaucrat  bureaucratA;
    Bureaucrat  bureaucratB("B", 75);
    Form        formA;
    Form        formB("FormB", 175, 0);

    std::cout << std::endl;
    bureaucratA.decrementGrade();
	std::cout << bureaucratA;
    std::cout << formA;
    std::cout << formB;
    bureaucratA.signForm(formA);
    std::cout << formA;
    std::cout << std::endl;
	bureaucratA.incrementGrade();
    bureaucratA.signForm(formA);
    std::cout << formA;
    std::cout << std::endl;
	std::cout << bureaucratA;
    std::cout << bureaucratB;
    std::cout << std::endl;
    std::cout << "=== Program Bureaucrat ended ===" << std::endl;
    return 0;
}
