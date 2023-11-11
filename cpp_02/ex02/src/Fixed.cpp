/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:07:25 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/11 00:06:27 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
}

Fixed::Fixed( const int int_number )
{
	this->number = int_number << this->fract_bits;
}

Fixed::Fixed( const float float_number )
{
	this->number = roundf(float_number * (1 << this->fract_bits));
}



Fixed::Fixed( const Fixed& original )
{
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	if (this != &original)
	{
		this->number = original.getRawBits();
	}
	return *this;
}



Fixed::~Fixed()
{
}



bool	Fixed::operator>(const Fixed value) const
{
	return (this->toFloat() > value.toFloat());
}

bool	Fixed::operator<(const Fixed value) const
{
	return (this->toFloat() < value.toFloat());
}

bool	Fixed::operator>=(const Fixed value) const
{
	return (this->toFloat() >= value.toFloat());
}

bool	Fixed::operator<=(const Fixed value) const
{
	return (this->toFloat() <= value.toFloat());
}

bool	Fixed::operator==(const Fixed value) const
{
	return (this->toFloat() == value.toFloat());
}

bool	Fixed::operator!=(const Fixed value) const
{
	return (this->toFloat() != value.toFloat());
}



Fixed	Fixed::operator+(const Fixed value) const
{
	return (this->toFloat() + value.toFloat());
}

Fixed	Fixed::operator-(const Fixed value) const
{
	return (this->toFloat() - value.toFloat());
}

Fixed	Fixed::operator*(const Fixed value) const
{
	return (this->toFloat() * value.toFloat());
}

Fixed	Fixed::operator/(const Fixed value) const
{
	if (value.number != 0)
		return (this->toFloat() / value.toFloat());
	else
	{
		std::cout << "Undefined" << std::endl;
		return -1;
	}
}



Fixed	Fixed::operator++(void)
{
	number++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed	Fixed::operator--(void)
{
	number--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}



Fixed&	Fixed::min(Fixed& value_a, Fixed& value_b)
{
	if (value_a.toFloat() <= value_b.toFloat())
		return value_a;
	else
		return value_b;
}

const	Fixed& Fixed::min(const Fixed& value_a, const Fixed& value_b)
{
	if (value_a.toFloat() <= value_b.toFloat())
		return value_a;
	else
		return value_b;
}

Fixed&	Fixed::max(Fixed& value_a, Fixed& value_b)
{
	if (value_a.toFloat() >= value_b.toFloat())
		return value_a;
	else
		return value_b;
}

const	Fixed& Fixed::max(const Fixed& value_a, const Fixed& value_b)
{
	if (value_a.toFloat() >= value_b.toFloat())
		return value_a;
	else
		return value_b;
}



int Fixed::getRawBits( void ) const
{
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