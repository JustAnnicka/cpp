/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:21:17 by aehrl             #+#    #+#             */
/*   Updated: 2026/02/03 16:19:01 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



Base *generate(void){
    int x =  rand() % 10;  

   // std::cout << "random num is: " << x << std::endl;
    if (x <= 3)
        return (new A);
    else if (x <= 6)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p){
    if (p == NULL)
    {
        std::cout << "Error\nBase is pointer to NULL. Not valid." << std::endl;
        return ;
    }
    try {
        if (dynamic_cast<A*>(p))
            std::cout << "Identified type by pointer: A" << std::endl;      
        else if (dynamic_cast<B*>(p))
            std::cout << "Identified type by pointer: B" << std::endl;      
        else if (dynamic_cast<C*>(p))
            std::cout << "Identified type by pointer: C" << std::endl;
        /* if (dynamic_cast<A*>(p))
            std::cout << "Identified type by pointer: A" << std::endl;      
        else if (dynamic_cast<B*>(p))
            std::cout << "Identified type by pointer: B" << std::endl;      
        else if (dynamic_cast<C*>(p))
            std::cout << "Identified type by pointer: C" << std::endl; */
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void    identify(Base& p){
   
    try{
        A   &Aref =  dynamic_cast<A&>(p);
        (void) &Aref;
        std::cout << "Identified type by reference: A" << std::endl;
    }
    catch (std::exception& e){
        try{
             B   &Bref =  dynamic_cast<B&>(p);
            (void) &Bref;
            std::cout << "Identified type by reference: B" << std::endl;
        }
        catch (std::exception& e)
        {   
            try{
                C   &Cref =  dynamic_cast<C&>(p);   
                (void) &Cref;
                std::cout << "Identified type by reference: C" << std::endl;
            }
            catch (std::exception& e){
                std::cout << e.what() << std::endl;
            }
        }
    }
    
}

int main() {
    std::cout << "=== Program Serialize started ===" << std::endl;
    
    Base *null0 = NULL;
    Base &null1 = *null0;
    Base *r1 = generate();
    Base *r2 = generate();
    Base *r3 = generate();
    Base *r4 = generate();
    Base *r5 = generate();
    Base &ref1 = *r1;
    Base &ref2 = *r2;
    Base &ref3 = *r3;
    Base &ref4 = *r4;
    Base &ref5 = *r5;
   
    std::cout << "=== BASE IS NULL ===" << std::endl;
    identify(null0);
    identify(null1);
    std::cout << "=== IDENTIFY POINTER ===" << std::endl;
    identify(r1);
    identify(r2);
    identify(r3);
    identify(r4);
    identify(r5);
    std::cout << "=== IDENTIFY POINTER ===" << std::endl;
    identify(ref1);
    identify(ref2);
    identify(ref3);
    identify(ref4);
    identify(ref5);
    std::cout << "=== Program Serialize ended ===" << std::endl;
    
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    return 0;
}