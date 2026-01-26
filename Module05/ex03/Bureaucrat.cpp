/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/26 15:31:19 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"){
    std::cout << "Bureaucrat default constructor called" << std::endl;
    _grade = 75;
}

Bureaucrat::Bureaucrat(std::string name, int grade ) : _name(name) {
    std::cout << "Bureaucrat assignment constructor called" << std::endl;
    try {
        setGrade(grade);
    }
    catch (std::exception &e){
        std::cout << this->getName() << ", ";
        std::cout << e.what();
        std::cout << "default grade 75 assigned" << std::endl;
        _grade = 75;
    } 
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;

    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) {    
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ptr){
	os << ptr.getName() << ", bureaucrat grade: " << ptr.getGrade() << std::endl;
	return (os);
}

/*  ----------  SETTERS & GETTERS ----------  */

void Bureaucrat::setGrade(int n){
    if (n < 1)
        throw (GradeTooHighException());
    else if (n > 150)
        throw (GradeTooLowException()); 
    else
        _grade = n;
}

std::string Bureaucrat::getName(void) const{
    return (this->_name);
}
int Bureaucrat::getGrade(void) const{
    return (this->_grade);
}

/*  ----------  OTHER MEMBER FUNCTIONS ----------  */

void Bureaucrat::signForm(AForm &ref){
    try{
        ref.beSigned(*this);
        std::cout << this->getName() << " signed " << ref.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn’t sign " << ref.getName()
                  << " because " << e.what();
    }
}

void Bureaucrat::executeForm(AForm const  & form) const{
    try{
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (const AForm::FormNotSigned &e)
    {
        std::cout << this->getName() << " couldn’t execute  " << form.getName()
                  << " because " << e.what();
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn’t execute  " << form.getName()
                  << " because " << e.what();
    }
    catch (...)
    {
        std::cout << "ANOTHER REASON" << std::endl;
    }
}


/*  ----------  INCREMENT & DECREMENT MEMBER FUNCTIONS ----------  */

void Bureaucrat::incrementGrade(void)
{
    try{
        this->setGrade(_grade - 1);
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " -> ";
        std::cout << e.what();
    }
}

void Bureaucrat::decrementGrade(void)
{
    try{
        this->setGrade(_grade + 1);
    }
    catch (std::exception &e){
        std::cout << this->getName() << " -> ";
        std::cout << e.what();
    }
}

/*  ----------  EXCEPTIONS----------  */

const char  *Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Bureaucrat: Grade too high. Must be between 1 & 150 \n");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Bureaucrat: Grade too low. Must be between 1 & 150 \n");
}
