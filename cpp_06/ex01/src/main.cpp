/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:34:59 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 15:09:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
    std::cout << "Data is \"Don\'t\", \"Panic\" and 42" << std::endl;
    Data *data = new Data("Don\'t", "Panic", 42);
    std::cout << "Pointer data - " << data << std::endl;
    std::cout << "Public data - " << data->publicData << std::endl;
    std::cout << "Private data - " << data->getPrivateData() << std::endl;
    std::cout << "Private number - " << data->getPrivateNumber() << std::endl;
    std::cout << std::endl;

    std::cout << "After serialization:" << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Raw pointer - " << raw << std::endl;
    std::cout << std::endl;

    std::cout << "After deserialization:" << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Raw pointer - " << ptr << std::endl;
    std::cout << "Public data - " << ptr->publicData << std::endl;
    std::cout << "Private data - " << ptr->getPrivateData() << std::endl;
    std::cout << "Private number - " << ptr->getPrivateNumber() << std::endl;

    delete data;
    return (0);
}
