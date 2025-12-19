/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:47 by aehrl             #+#    #+#             */
/*   Updated: 2025/12/17 19:04:25 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
 #define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
        virtual ~Brain();
        std::string getIdea(int i);
    
    private:
        std::string _ideas[100];
};

#endif // BRAIN_HPP
