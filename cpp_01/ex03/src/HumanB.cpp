/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:14:35 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/26 19:45:02 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	weapon = NULL;
}

HumanB::HumanB(Weapon* weapon, std::string name) : weapon(weapon), name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (weapon == NULL)
		std::cout << name << " attacks with their bare hands" << std::endl;
	else
		std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;

}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}