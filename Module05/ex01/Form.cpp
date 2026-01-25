/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/25 18:08:23 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default form name"), _gradeSign(75), _gradeExec(75){
    std::cout << "Form default constructor called" << std::endl;
    _signed = false;
}

//Form::Form(const std::string name, int gs, int ge) : _name(name), _gradeSign(gs < 1 ? 1 : (gs > 150 ? 150 : gs )), _gradeExec(gs < 1 ? 1 : (ge > 150 ? 150 : ge )){  
Form::Form(const std::string name, int gs, int ge) : _name(name), _gradeSign(gs), _gradeExec(gs){  
    std::cout << "Form assignment constructor called" << std::endl;
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

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec){
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy data members here
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Form &ptr){
	os << ptr.getName() << ", Form grade to sign: " << ptr.getGradeSign();
    os << " , Form grade to excecute " << ptr.getGradeExec() << ", signed = " << (ptr.getSigned() ? "True" : "False") <<std::endl;
	return (os);
}

/*  ----------  SETTERS & GETTERS ----------  */

/* void    Form::setGradeSign(int n){
    if (n < 1)
        throw(GradeTooHighException());
    else if(n > 150)
        throw(GradeTooLowException());
    else
        _gradeSign = n;
}

void    Form::setGradeExec(int n){
    if (n < 1)
        throw(GradeTooHighException());
    else if(n > 150)
        throw(GradeTooLowException());
    else
        _gradeExec = n;
} */

/* void    Form::setSigned(){
    if (n > _gradeSign)
        throw(GradeTooLowException());
    else
        _signed = true;
}
 */
void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
            throw(GradeTooLowException());
    _signed = true;
 /*    catch(std::exception &e)
    {
        std::cout << e.what();
    } */

}

const std::string Form::getName() const{
    return(_name);
}

bool Form::getSigned() const{
    return(_signed);
}
int Form::getGradeSign() const{
    return(_gradeSign);
}
int Form::getGradeExec() const{
    return(_gradeExec);
}

/*  ----------  EXCEPTIONS----------  */
const char *Form::GradeTooHighException::what() const throw(){
    return ("Form: grade too high.\n");
}
const char *Form::GradeTooLowException::what() const throw(){
    return ("Form: grade too low.\n");
}