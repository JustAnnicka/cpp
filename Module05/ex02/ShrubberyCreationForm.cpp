/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/25 21:55:55 by aehrl            ###   ########.fr       */
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
	std::fstream file(fname.c_str());
	if (file.fail())
		std::cout << "ferror" << std::endl;
	file << "T\nA\n";
}



/* 

The Worm's Turn
             _{\ _{\{\/}/}/}__
            {/{/\}{/{/\}(\}{/\} _
           {/{/\}{/{/\}(_)\}{/{/\}  _
        {\{/(\}\}{/{/\}\}{/){/\}\} /\}
       {/{/(_)/}{\{/)\}{\(_){/}/}/}/}
      _{\{/{/{\{/{/(_)/}/}/}{\(/}/}/}
     {/{/{\{\{\(/}{\{\/}/}{\}(_){\/}\}
     _{\{/{\{/(_)\}/}{/{/{/\}\})\}{/\}
    {/{/{\{\(/}{/{\{\{\/})/}{\(_)/}/}\}
     {\{\/}(_){\{\{\/}/}(_){\/}{\/}/})/}
      {/{\{\/}{/{\{\{\/}/}{\{\/}/}\}(_)
     {/{\{\/}{/){\{\{\/}/}{\{\(/}/}\}/}
      {/{\{\/}(_){\{\{\(/}/}{\(_)/}/}\}
        {/({/{\{/{\{\/}(_){\/}/}\}/}(\}
         (_){/{\/}{\{\/}/}{\{\)/}/}(_)
           {/{/{\{\/}{/{\{\{\(_)/}
            {/{\{\{\/}/}{\{\\}/}
             {){/ {\/}{\/} \}\}
             (_)  \.-'.-/
         __...--- |'-.-'| --...__
  _...--"   .-'   |'-.-'|  ' -.  ""--..__
-"    ' .  . '    |.'-._| '  . .  '   jro
.  '-  '    .--'  | '-.'|    .  '  . '
         ' ..     |'-_.-|
 .  '  .       _.-|-._ -|-._  .  '  .
             .'   |'- .-|   '.
 ..-'   ' .  '.   `-._.-´   .'  '  - .
  .-' '        '-._______.-'     '  .
       .      ~,
   .       .   |\   .    ' '-.
   ___________/  \____________
  /  Why is it, when you want \
 |  something, it is so damn   |
 |    much work to get it?     |
  \___________________________/
------------------------------------------------
Thank you for visiting https://asciiart.website/
This ASCII pic can be found at
https://asciiart.website/art/3815



*/