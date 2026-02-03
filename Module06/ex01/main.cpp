/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/02/02 18:59:36 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"


int main() {
    std::cout << "=== Program Serialize started ===" << std::endl;
    Data *ptr = new Data;
    std::cout << "=== Initializing Data ===" << std::endl;
    ptr->n = 42;
    ptr->f = 42.42f;
    ptr->d = 42.0;


    std::cout << "=== Info of Data ===" << std::endl;
    std::cout << "Address: " << ptr << std::endl;
    std::cout << "integer: " << ptr->n << std::endl;
    std::cout << "float: " << ptr->f << std::endl;
    std::cout << "double: " << ptr->d << std::endl;
    
    std::cout << "=== Serialize pointer of Data ===" << std::endl;
    uintptr_t x =  Serializer::serialize(ptr);
    std::cout << "Return:  ===" << x << std::endl;
    std::cout << "=== Serialize uintptr ===" << std::endl;
    Data *y =  Serializer::deserialize(x);
    std::cout << "Original:  ===" << ptr << std::endl;
    std::cout << "Return:  ===" << y << std::endl;

    delete ptr;
    std::cout << "=== Program Serialize ended ===" << std::endl;
    return 0;
}
