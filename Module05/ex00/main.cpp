/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/24 22:39:22 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Program Bureaucrat started ===" << std::endl;
    Bureaucrat bureaucratA;
    Bureaucrat bureaucratB("B", 75);
    Bureaucrat bureaucratC("C", 175);

    bureaucratA.decrementGrade();
	std::cout << bureaucratA;
	bureaucratA.incrementGrade();
	std::cout << bureaucratA;
    std::cout << bureaucratB;
    std::cout << bureaucratC;
    std::cout << "=== Program Bureaucrat ended ===" << std::endl;
    return 0;
}
