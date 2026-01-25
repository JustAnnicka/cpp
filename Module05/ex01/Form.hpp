/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/25 18:06:55 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form();
        Form(const std::string name, const int gradeSign, const int gradeExec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        
        const std::string   getName() const;
        bool                getSigned() const;
        int                 getGradeSign() const;
        int                 getGradeExec() const;
        
        void                beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    
    private:
        const std::string   _name;
        bool                _signed; //false on construction
        const int           _gradeSign ;
        const int           _gradeExec; 

};

std::ostream& operator<<(std::ostream &os, const Form &ptr);

#endif // FORM_HPP

