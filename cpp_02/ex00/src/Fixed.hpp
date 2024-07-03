/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:01:15 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/09 19:43:10 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int number;
	static const int fract_bits = 8;

public:
	Fixed();
	Fixed( const Fixed& original );
	Fixed& operator=(const Fixed& value);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif