/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/19 19:18:26 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
	//Animal VirtualTest;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    
    Animal* animals[10];
	Animal** aux;
	int n = 0;
	while(n < 5)
	{
		std::cout << "Dog nº " << n << std::endl;
		animals[n++] = new Dog();
	}
	while(n < 10)
	{
		std::cout << "Cat nº " << n << std::endl;
		animals[n++] = new Cat();
	}
	
	aux = animals;
	for(int i = 0; i < 10; i++)
	{
		std::cout << "Nº " << i << " Type: " << aux[i]->getType() << std::endl;
		aux[i]->makeSound();
	}
	for(int j = 0; j < 10; j++)
		delete animals[j];

    delete j;//should not create a leak
    delete i;
    return 0;
}

