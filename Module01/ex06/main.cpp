/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:22:10 by aehrl             #+#    #+#             */
/*   Updated: 2025/10/01 13:49:42 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int	main(int argc, char	*argv[])
{
	if (argc != 2)
		return(std::cout << "Error\nwrong input", 1);

	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
