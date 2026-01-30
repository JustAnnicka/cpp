/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/30 14:30:32 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy data members here
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

int check_decimal_float(std::string input)
{
    int check = 0;
    std::string::size_type i = 0;
    if (input[i] == '-')
        i++;
    while(i < input.length() - 1)
    {
        if (input[i] == '.')
        {
            check++;
            if (check != 1)
                return (0);
        }
        else if (!std::isdigit(input[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_number(std::string input, char type)
{
    int check = 0;
    std::string::size_type i = 0;
    int x = 0;
    if (type == 'f')
        x = 1;
    if (input[i] == '-')
        i++;
    std::cout << "enter check number float:" << x << std::endl;
    while(i < input.length() - x)
    {
        if (input[i] == '.')
        {
            check++;
            if (check != 1)
                return (0);
        }
        else if (!std::isdigit(input[i]))
            return (0);
        i++;
    }
    return (1);
}

int psuedo_literal(std::string input, char type)
{
    std::string f1 = "-inff";
    std::string f2 = "+inff";
    std::string f3 = "nanf";
    std::string d1 = "-inf";
    std::string d2 = "+inf";
    std::string d3 = "nan";
    
    std::cout << "enter psuedo" << std::endl;
    if (type == 'f' && input.compare(f1) != 0  && input.compare(f2) != 0 && input.compare(f3) != 0)
        return (0);
    if (type == 'd' && input.compare(d1) != 0  && input.compare(d2) != 0 && input.compare(d3) != 0)
        return (0);
    std::cout << "Is psuedo" << std::endl;
    return (1);
}

int parse(std::string input){
    
    std::string::size_type i = 0;
    int dot = 0;
    int minus = 0;
    int f = 0;
//    while ( (i<input.length()) && (std::isalnum(input[i])) ) {++i;}
//    std::cout << "The first " << i << " characters are alphanumeric.\n";
    while ( (i<input.length()) && (std::isprint(input[i])) ) {
        if (input[i] == '.')
            dot++;
        if (input[i] == '-')
            minus++;
        if (input[i] == 'f')
            f++;
        ++i;
    }
   // std::cout << "The first " << i << " characters are printable.\n";
    if (minus > 1 || dot > 1 || f > 2)
        return (0);
   // std::cout << i << " ---- " << input.length() << std::endl;
    if (std::isprint(input[0]) && !std::isdigit(input[0]) && i == 1)
        return (1); // is a char
    i = 0;
    if (dot == 0 && check_number(input, 'i'))
        return (2);

    
    else if (f >= 1 && input[input.length() - 1] == 'f') // can i do + 1 on string to pass from 1st position on minus?
    {
        std::cout << "is float" << std::endl;
        if (psuedo_literal(input , 'f'))
            return (3);
        if (!check_number(input, 'f'))
            return (0);
        return (3); // is a float
    }
    else
    {
        std::cout << "is double" << std::endl;
        if (psuedo_literal(input, 'd'))
            return (4);
        if (!check_number(input, 'i'))
            return (0);
        return (4); // is a double
    }

    return (0);
        //iscntrl ??
}

void ScalarConverter::convert(std::string literal){
    std::cout << "Entered Convert: " << literal << std::endl;
    int level = parse(literal);

    switch(level)
    {
        case 0:
        {
            std::cout << "Not a valid argument" << std::endl;
            return ;
        }
        case 1:
            std::cout << "char: " << std::endl;
        case 2:
        {
            //this has to be handled in the int function
            //if level == 2;
            //    std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << std::endl;
        }
        case 3:
        {
            //this has to be handled in the float function
            //if level == 3;
           //     std::cout << "char: Non impossible\nint: impossible" << std::endl;
            std::cout << "float: " << std::endl;
        }
        case 4:
        {
            //does there have to be a special handling of float for nanf??
            std::cout << "float: " << std::endl;
        }
    }
    //check for what happens with ñ or other extended ASCII letters <- we might be able to ignore this
    //make cases -> if not char is not displayable / impossible print those messages
}