/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:34:22 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 15:13:19 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : publicData("publicData"), privateData("privateData"), privateNumber(0) {
    return ;
}
Data::Data(std::string public_data, std::string private_data, int private_number) : publicData(public_data), privateData(private_data), privateNumber(private_number) {
    return ;
}
Data::~Data(void) {
    return ;
}
Data::Data(Data const &source) {
    *this = source;
    return ;
}
Data &Data::operator=(Data const &source) {
    if (this != &source)
    {
        publicData = source.publicData;
        privateData = source.privateData;
        privateNumber = source.privateNumber;
    }
    return (*this);
}

std::string Data::getPrivateData(void) const {
    return (privateData);
}
int Data::getPrivateNumber(void) const {
    return (privateNumber);
}
