/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:35:26 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/25 19:08:46 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " was shot in the head!" << std::endl;
}

void Zombie::announce ( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}