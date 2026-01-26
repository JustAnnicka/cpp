/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/25 21:40:51 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
 #define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        
        const std::string   getName() const;
        bool                getSigned() const;
        int                 getGradeSign() const;
        int                 getGradeExec() const;
        void                beSigned(Bureaucrat &bureaucrat);


        void execute(Bureaucrat const & executor) const; //const?
        virtual void execute_derived() const = 0;
        
    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class FormNotSigned : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    
    private:
        const std::string   _name;
        bool                _signed; //false on construction
        const int           _gradeSign;
        const int           _gradeExec; 

};

std::ostream& operator<<(std::ostream &os, const AForm &ptr);

#endif // AFORM_HPP

