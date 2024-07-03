/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:46:22 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/22 18:38:03 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const Cat& value)
{
	if (this == &value)
		return;
	type = value.type;
	brain = new Brain(*value.brain);
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = value;
}

Cat	&Cat::operator=(const Cat& value)
{
	if (this == &value)
		return (*this);
	type = value.type;
	brain = new Brain(*value.brain);
	return (*this);
	std::cout << "Cat copy assignment operator overload called!" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}