/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:01:15 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/07 20:02:18 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int m_int;
	static const int m_fract = 8;

public:
	Fixed();
	Fixed( const Fixed& original );
	Fixed& operator=(const Fixed& value);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif