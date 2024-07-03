/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:00:40 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/14 17:16:06 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clappy("Clappy");

	clappy.attack("Trappy");

	clappy.takeDamage(7);
	clappy.beRepaired(2);
	clappy.beRepaired(15);

	for (int i = 0; i < 8; i++)
		clappy.attack("Trappy");

	clappy.takeDamage(7);
	clappy.takeDamage(7);
	clappy.beRepaired(15);

	clappy.takeDamage(7);

	return 0;
}