/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/12 18:52:19 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/* add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, ==, and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
    post-decrement) operators, which will increase or decrease the fixed-point value by
    the smallest representable ϵ, such that 1 + ϵ > 1.
    Add these four public overloaded member functions to your class:
• A static member function min that takes two references to fixed-point numbers as
    parameters, and returns a reference to the smallest one.
• A static member function min that takes two references to constant fixed-point
    numbers as parameters, and returns a reference to the smallest one.
• A static member function max that takes two references to fixed-point numbers as
    parameters, and returns a reference to the greatest one.
• A static member function max that takes two references to constant fixed-point
    numbers as parameters, and returns a reference to the greatest one. */

class Fixed {
    public:
        Fixed();
        Fixed(const int param);
        Fixed(const float param);
        Fixed(const Fixed &ptr);
        Fixed &operator=(const Fixed &ptr);
        ~Fixed();

        int		getRawBits(void) const;
		void	setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        
        static Fixed& min(Fixed& v1, Fixed& v2);
        static const Fixed& min(const Fixed& v1, const Fixed& v2);
        static Fixed& max(Fixed& v1, Fixed& v2);
        static const Fixed& max(const Fixed& v1, const Fixed& v2);
        
        //DEFENITION OF COMPARISON OPERATORS
        bool operator<(const Fixed& toCompare) const;
        bool operator>(const Fixed& toCompare) const;
        bool operator>=(const Fixed& toCompare) const;
        bool operator<=(const Fixed& toCompare) const;
        bool operator==(const Fixed& toCompare) const;
        bool operator!=(const Fixed& toCompare) const;

        //DEFENITION OF ARITHMETIC OPERATORS
        Fixed operator+(const Fixed& toAdd) const;
        Fixed operator-(const Fixed& toSubtract) const;
        Fixed operator*(const Fixed& toMultiply) const;
        Fixed operator/(const Fixed& toDivide) const;

        //DEFENITION OF INCREMENT/DECREMENT OPERATOS
        Fixed operator++(void);
        Fixed operator--(void);
        Fixed operator++(int); //post-increment dummy int
        Fixed operator--(int); //post-decrement dummy int
   
     
        
    private:
		int _nbr_v;
		static const int bits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &ptr);

#endif // FIXED_HPP
