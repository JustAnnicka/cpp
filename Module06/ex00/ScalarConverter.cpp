/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/30 16:49:57 by aehrl            ###   ########.fr       */
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
        // nothing to copy
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

int psuedo_literal(std::string input)
{  
    //does there have to be a special handling of float for nanf??
    if (input.compare("-inff") == 0 || input.compare("-inf") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (1);
    }
    if (input.compare("+inff") == 0 || input.compare("+inf") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return (1);
    }
    if (input.compare("nanf") == 0 || input.compare("nan") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (1);
    }
//    std::cout << "Is not float psuedo" << std::endl;
    return (0);
}

int parse(std::string input){
    
    std::string::size_type i = 0;
    int dot = 0;
    int minus = 0;
    int f = 0;
    while ( (i<input.length()) && (std::isprint(input[i])) ) {
        if (input[i] == '.')
            dot++;
        if (input[i] == '-')
            minus++;
        if (input[i] == 'f')
            f++;
        ++i;
    }
    if (minus > 1 || dot > 1 || f > 2)
        return (0);
    if (std::isprint(input[0]) && !std::isdigit(input[0]) && i == 1)
        return (1); // is a char
    i = 0;
    if (dot == 0 && check_number(input, 'i'))
        return (2);
     if (psuedo_literal(input))
        return (5);
    else if (f >= 1 && (input[input.length() - 1] == 'f')) // can i do + 1 on string to pass from 1st position on minus?
    {
        if (!check_number(input, 'f'))
            return (0);
        return (3); // is a float
    }
    else
    {
        if (!check_number(input, 'i'))
            return (0);
        return (4); // is a double
    }

    return (0);
        //iscntrl ??
}

void convert_int(std::string literal, int level){
    int n;
    if (level == 1)
       n = static_cast<int>(literal[0]);
    else
    {
        std::stringstream ss(literal);
        ss >> n;
        //check if it goes beyong MAX & MIN
        char c;
        c = static_cast<char>(n);
        if (!std::isprint(n))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
    }
    std::cout << "int: " <<  n << std::endl;
}

void convert_float(std::string literal, int level){
      float n;
    if (level == 1)
       n = static_cast<float>(literal[0]);
    else
    {  
        convert_int(literal, level);
        std::stringstream ss(literal);
        ss >> n;
        //check if it goes beyong MAX & MIN
    }
    //check what precision we need for evaluation!!
    std::cout << "float: " << std::setprecision(1) << std::fixed << n << "f" << std::endl;
}

void convert_double(std::string literal, int level){
      double n;
    if (level == 1)
       n = static_cast<double>(literal[0]);
    else
    {
        if (level == 4)
            convert_float(literal, level);
        std::stringstream ss(literal);
        ss >> n;
        //check if it goes beyong MAX & MIN
    }
    //check what precision we need for evaluation!!
    std::cout << "double: " << std::setprecision(1) << std::fixed << n << std::endl;
}

void ScalarConverter::convert(std::string literal){
    int level = parse(literal);

    switch(level)
    {
        case 0:
        {
            std::cout << "Not a valid argument" << std::endl;
            return ;
        }
        case 1:
            std::cout << "char: '" << literal << "'" << std::endl;
        case 2: 
            convert_int(literal, level);
        case 3:
            convert_float(literal, level);
        case 4:
            convert_double(literal, level);
        default:;
    }
}