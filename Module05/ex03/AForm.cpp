/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/26 18:07:34 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default form name"), _gradeSign(75), _gradeExec(75){
    std::cout << "AForm default constructor called" << std::endl;
    _signed = false;
}

//AForm::AForm(const std::string name, int gs, int ge) : _name(name), _gradeSign(gs < 1 ? 1 : (gs > 150 ? 150 : gs )), _gradeExec(gs < 1 ? 1 : (ge > 150 ? 150 : ge )){  
AForm::AForm(const std::string name, int gs, int ge) : _name(name), _gradeSign(gs), _gradeExec(ge){  
    std::cout << "AForm assignment constructor called" << std::endl;
    _signed = false;
    try{
        
        if (gs > 150)
        {
            std::cout << "Grade Signed: ";
            throw(GradeTooLowException());
        }
		if (gs < 1)
        {
            std::cout << "Grade Signed: ";
			throw(GradeTooHighException());
        }
	}
	catch(std::exception &e){
		std::cout << e.what();
	}
    try{
        
        if (ge > 150)
        {
            std::cout << "Grade Exection: ";
            throw(GradeTooLowException());
        }
		if (ge < 1)
        {
            std::cout << "Grade Exection: ";
			throw(GradeTooHighException());
        }
	}
	catch(std::exception &e){
		std::cout << e.what();
	}
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec){
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy data members here
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const AForm &ptr){
	os << ptr.getName() << ", AForm grade to sign: " << ptr.getGradeSign();
    os << " , AForm grade to execute " << ptr.getGradeExec() << ", signed = " << (ptr.getSigned() ? "True" : "False") <<std::endl;
	return (os);
}

/*  ----------  OTHER MEMBER FUNCTIONS ----------  */

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
            throw(GradeTooLowException());
    _signed = true;
}

void AForm::execute(Bureaucrat const & executor) const{
    if (this->getSigned() == false)
        throw(FormNotSigned());
    if (executor.getGrade() > this->getGradeExec())
    {
        throw(GradeTooLowException());
    }
    this->execute_derived();
}

/*  ----------  SETTERS & GETTERS ----------  */

const std::string AForm::getName() const{
    return(_name);
}
bool AForm::getSigned() const{
    return(_signed);
}
int AForm::getGradeSign() const{
    return(_gradeSign);
}
int AForm::getGradeExec() const{
    return(_gradeExec);
}


/*  ----------  EXCEPTIONS----------  */
const char *AForm::GradeTooHighException::what() const throw(){
    return ("AForm: grade too high.\n");
}
const char *AForm::GradeTooLowException::what() const throw(){
    return ("AForm: grade too low.\n");
}
const char *AForm::FormNotSigned::what() const throw(){
    return ("Form: not signed.\n");
}