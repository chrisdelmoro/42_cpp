/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:07:25 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/14 19:29:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : Name("Default ClapTrap")
{
	std::cout << "Default ClapTrap's constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << Name << "'s constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& value)
{
	*this = value;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& value)
{
	Name = value.Name;
	HitPoints = value.HitPoints;
	EnergyPoints = value.EnergyPoints;
	AttackDamage = value.AttackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << Name << "'s destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		EnergyPoints -= 1;
		std::cout << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << Name << " has no HitPoints or EnergyPoints left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints > 0)
	{
		HitPoints -= amount;
		std::cout << Name << " took " << amount << " points of damage!" << std::endl;
		if (HitPoints < 0)
		{
			HitPoints = 0;
			std::cout << Name << " died! :(" << std::endl;
		}

	}
	else
	{
		std::cout << "Stop it! ClapTrap " << Name << " is already dead!! D:" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		HitPoints += amount;
		EnergyPoints -= 1;
		std::cout << Name << " repaired itself by " << amount << " points! >:D" << std::endl;
	}
	else
	{
		std::cout << Name << " has no hit points or energy points left to heal itself. :/" << std::endl;
	}
}