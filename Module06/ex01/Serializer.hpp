/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2026/02/02 17:46:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>


class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer(){}
		Serializer(const Serializer &){}
		~Serializer(){}
		void operator=(const Serializer &){}
};

#endif // SERIALIZER_HPP
