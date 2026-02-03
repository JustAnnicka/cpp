/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:12:09 by aehrl             #+#    #+#             */
/*   Updated: 2026/02/02 18:57:08 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t x = reinterpret_cast<uintptr_t>(ptr);
    return (x);
}

Data* Serializer::deserialize(uintptr_t raw){

    Data *ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}