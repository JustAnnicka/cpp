/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/01/27 16:22:12 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"


int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        std::cout << "Wrong number of argruments" << std::endl;
        return (1);
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}

/*  char literals: 'c' , 'a'
    int literals: 0, -42, 42
    float literals: 0.0f, -4.2f, 4.2f
        -> psuedo literals: -inff, +inff, nanf
    double literals: 0.0, -4.2, 4.2 
        -> psuedo literals: -inf, +inf, nan

*/


/* You have to first detect the type of the literal passed as a parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values. */

//EXPECTED OUTPUT

/* ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0 */