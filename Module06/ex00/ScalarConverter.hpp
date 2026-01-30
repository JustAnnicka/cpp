/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/30 16:04:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
//should not be able to instantiate
class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        virtual ~ScalarConverter();

        static void convert(std::string literal);

    private:
    // Add private members here
};

//ADD STATIC FUNCTIONS HERE

#endif // SCALARCONVERTER_HPP


/* Authorized: Any function to convert from a string to an int, a float, or a
double. This will help, but won’t do the whole job. */

/* Write a class ScalarConverter that will contain only one static method "convert"
that will take as a parameter a string representation of a C++ literal in its most common
form and output its value in the following series of scalar types:
• char
• int
• float
• double
As this class doesn’t need to store anything at all, it must not be instantiable by users.
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non-displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, print an informative message.
Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo-literals as well (you know, for science): -inff, +inff,
and nanf.
9
C++ - Module 06 C++ casts
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and
nan. */