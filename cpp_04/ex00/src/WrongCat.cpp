/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:43:38 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/21 16:51:19 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "Wrong Cat";
	std::cout << "Wrong cat constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& value)
{
	std::cout << "Wrong cat copy constructor called!" << std::endl;
	*this = value;
}

WrongCat	&WrongCat::operator=(const WrongCat& value)
{
	std::cout << "Wrong cat copy assignment operator overload called!" << std::endl;
	if (this != &value)	
		type = value.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong cat destructor called!" << std::endl;
}

void	WrongCat::makeSound() const 
{
	std::cout << "Wrong cat sound.." << std::endl;
}