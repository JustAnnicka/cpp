/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/25 21:58:02 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #ifndef SHRUBBERYCREATIONFORM_HPP
 #define SHRUBBERYCREATIONFORM_HPP */
#pragma once
#include <iostream>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(); //Sign 145, Exec 137
        ShrubberyCreationForm(const std::string &target); //Sign 145, Exec 137
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        void execute_derived() const;
    private:
        std::string  _target; //_shrubbery  creates a file and wrties ASCII trees inside ClapTrap(name + "_clap_name")
};

//#endif // SHRUBBERYCREATIONFORM_HPP
