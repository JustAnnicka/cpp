/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:16:30 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/04 14:16:49 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class	Fixed
{
	private:
		int nbr_v;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &ptr);
		void operator=(const Fixed &ptr);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif