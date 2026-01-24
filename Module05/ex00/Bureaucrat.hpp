/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/24 22:24:34 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName(void) const;
        int         getGrade(void) const;
        void        setGrade(int n);

        // increment / decrement should be done with the correct operators 
      /*   You must implement an overload of the insertion («) operator to print output in the
            following format (without the angle brackets): <name>, bureaucrat grade <grade>. */
        
        void incrementGrade(void); //this will make the number lower
        void decrementGrade(void); //this will make the number higher

        class GradeTooHighException : public std::exception {
            public:
               virtual const char* what() const throw(); //lower than 1
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw(); // higher than 150
        };

        
    private:
        const std::string   _name;
        int                 _grade; 
        
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ptr);

#endif // BUREAUCRAT_HPP
