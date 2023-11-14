/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:01:15 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/14 16:59:47 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string Name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;
public:
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap& value);
	ClapTrap& operator=(const ClapTrap& value);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();
};

#endif