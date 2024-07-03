/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:07:25 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/09 19:44:49 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int int_number )
{
	std::cout << "Int constructor called" << std::endl;
	this->number = int_number << this->fract_bits;
}

Fixed::Fixed( const float float_number )
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(float_number * (1 << this->fract_bits));
}



Fixed::Fixed( const Fixed& original )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &original)
	{
		this->number = original.getRawBits();
	}
	return *this;
}



Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}



int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits( int const raw )
{
	this->number = raw;
}

float	Fixed::toFloat() const
{
	return ((float)number / (float)(1 << fract_bits));
}

int	Fixed::toInt() const
{
	return number >> fract_bits;
}



std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}