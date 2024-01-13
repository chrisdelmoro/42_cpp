/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:34:52 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 14:49:15 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
    return ;
}
Serializer::~Serializer(void) {
    return ;
}
Serializer::Serializer(Serializer const &source) {
    *this = source;
    return ;
}
Serializer &Serializer::operator=(Serializer const &source) {
    if (this != &source)
        *this = source;
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}
Data *Serializer::deserialize(uintptr_t raw) {
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}
