/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:00:40 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/14 19:53:45 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
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
	}

	{
		std::cout << std::endl;
		ScavTrap trappy("Trappy");

		trappy.guardGate();

		trappy.attack("Fulaninho");
		trappy.takeDamage(35);
		trappy.beRepaired(20);
	}
	return 0;
}