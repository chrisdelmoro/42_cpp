/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:42:58 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/21 16:45:12 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

// Derived class
class	WrongCat : public WrongAnimal 
{
	public:
		WrongCat();
		WrongCat(const WrongCat& value);
		WrongCat& operator=(const WrongCat& value);
		~WrongCat();

		void makeSound() const;
};

#endif