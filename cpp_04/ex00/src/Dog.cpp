/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:50:30 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/21 16:28:43 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const Dog& value)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = value;
}

Dog	&Dog::operator=(const Dog& value)
{
	std::cout << "Dog copy assignment operator overload called!" << std::endl;
	Animal::operator=(value);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark! Bark!" << std::endl;
}