/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:40 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/25 20:31:19 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 10;
	std::string zombieName = "Rick";
	Zombie* horde = zombieHorde(hordeSize, zombieName);

	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();
	}

	delete[] horde;

	return 0;
}