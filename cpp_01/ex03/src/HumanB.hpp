/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:06:47 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/26 19:42:43 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONB_HPP
# define WEAPONB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon* weapon;
	std::string name;

public:
	HumanB(std::string name);
	HumanB(Weapon* weapon, std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon& weapon);
};

#endif