/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/26 16:25:13 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Schrubbery Creation Form", 145, 137){
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    _target = "default_target";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Schrubbery Creation Form", 145, 137){
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &other) {
       _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute_derived() const{
    std::string fname = _target + "_shrubbery";
	std::ofstream file(fname.c_str());
    if (file.is_open())
    {
       file  << "The Worm's Turn" << std::endl;
       file  << "             _{'\' _{'\'{'\'/}/}/}__" << std::endl;
       file  << "            {/{/'\'}{/{/'\'}('\'}{/'\'} _" << std::endl;
       file  << "           {/{/'\'}{/{/'\'}(_)'\'}{/{/'\'}  _" << std::endl;
       file  << "       {'\'{/('\'}'\'}{/{/'\'}'\'}{/){/'\'}'\'} /'\'}" << std::endl;
       file  << "       {/{/(_)/}{'\'{/)'\'}{'\'(_){/}/}/}/}" << std::endl;
       file  << "      _{'\'{/{/{'\'{/{/(_)/}/}/}{'\'(/}/}/}" << std::endl;
       file  << "     {/{/{'\'{'\'{'\'(/}{'\'{'\'/}/}{'\'}(_){'\'/}'\'}" << std::endl;
       file  << "     _{'\'{/{'\'{/(_)'\'}/}{/{/{/'\'}'\'})'\'}{/'\'}" << std::endl;
       file  << "     {/{/{'\'{'\'(/}{/{'\'{'\'{'\'/})/}{'\'(_)/}/}'\'}" << std::endl;
       file  << "     {'\'{'\'/}(_){'\'{'\'{'\'/}/}(_){'\'/}{'\'/}/})/}" << std::endl;
       file  << "      {/{'\'{'\'/}{/{'\'{'\'{'\'/}/}{'\'{'\'/}/}'\'}(_)" << std::endl;
       file  << "     {/{'\'{'\'/}{/){'\'{'\'{'\'/}/}{'\'{'\'(/}/}'\'}/}" << std::endl;
       file  << "      {/{'\'{'\'/}(_){'\'{'\'{'\'(/}/}{'\'(_)/}/}'\'}" << std::endl;
       file  << "        {/({/{'\'{/{'\'{'\'/}(_){'\'/}/}'\'}/}('\'}" << std::endl;
       file  << "          (_){/{'\'/}{'\'{'\'/}/}{'\'{'\')/}/}(_)" << std::endl;
       file  << "           {/{/{'\'{'\'/}{/{'\'{'\'{'\'(_)/}" << std::endl;
       file  << "            {/{'\'{'\'{'\'/}/}{'\'{'\''\'}/}" << std::endl;
       file  << "             {){/ {'\'/}{'\'/} '\'}'\'}" << std::endl;
       file  << "             (_)  '\'.-'.-/" << std::endl;
       file  << "         __...--- |'-.-'| --...__" << std::endl;
       file  << "  _...--'   .-'   |'-.-'|  ' -.  ''--..__" << std::endl;
       file  << "-'    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
       file  << ".  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
       file  << "         ' ..     |'-_.-|" << std::endl;
       file  << " .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
       file  << "             .'   |'- .-|   '." << std::endl;
       file  << " ..-'   ' .  '.   `-._.-´   .'  '  - ." << std::endl;
       file  << "  .-' '        '-._______.-'     '  ." << std::endl;
       file  << "       .      ~," << std::endl;
       file  << " .         .   |'\'   .    ' '-." << std::endl;
       file  << "   ___________/  '\'____________" << std::endl;
       file  << "  /  Why is it, when you want '\' " << std::endl;
       file  << " |  something, it is so damn   | " << std::endl;
       file  << " |    much work to get it?     |" << std::endl;
       file  << "  '\'___________________________/" << std::endl;
       file  << "------------------------------------------------" << std::endl;
       file  << "This ASCII pic can be found at https://asciiart.website/art/3815" << std::endl;
       file  << "------------------------------------------------" << std::endl;
       file  << "ex02" << std::endl;
       file  << "|__Bureaucrat.cpp" << std::endl;
       file  << "|__Bureaucrat.hpp" << std::endl;
       file  << "|__Makefile" << std::endl;
       file  << "|__main.cpp" << std::endl;
       file  << "|__AForm.cpp" << std::endl;
       file  << "|__AForm.hpp" << std::endl;
       file  << "|__PresidentialPardonForm.cpp" << std::endl;
       file  << "|__PresidentialPardonForm.hpp" << std::endl;
       file  << "|__RobotomyRequestForm.cpp" << std::endl;
       file  << "|__RobotomyRequestForm.hpp" << std::endl;
       file  << "|__ShrubberyCreationForm.cpp" << std::endl;
       file  << "|__ShrubberyCreationForm.hpp" << std::endl;     
       file.close();
       
    }
	if (file.fail())
		std::cout << "ferror" << std::endl;
}
