/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:01:15 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/09 19:56:59 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int number;
	static const int fract_bits = 8;

public:
	Fixed();
	Fixed( const int int_number );
	Fixed( const float float_number );
	Fixed( const Fixed& original );
	Fixed& operator=( const Fixed& value );
	~Fixed();

	bool	operator>(const Fixed value) const;
	bool	operator<(const Fixed value) const;
	bool	operator>=(const Fixed value) const;
	bool	operator<=(const Fixed value) const;
	bool	operator==(const Fixed value) const;
	bool	operator!=(const Fixed value) const;

	Fixed	operator+(const Fixed value) const;
	Fixed	operator-(const Fixed value) const;
	Fixed	operator*(const Fixed value) const;
	Fixed	operator/(const Fixed value) const;

	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);

	static			Fixed& min(Fixed& value_a, Fixed& value_b);
	static const	Fixed& min(const Fixed& value_a, const Fixed& value_b);
	static			Fixed& max(Fixed& value_a, Fixed& value_b);
	static const	Fixed& max(const Fixed& value_a, const Fixed& value_b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &fixed);

#endif