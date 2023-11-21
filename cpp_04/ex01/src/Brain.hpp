/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:27:32 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/21 20:00:47 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &value);
	Brain &operator=(const Brain &value);
	~Brain();

	std::string* getIdeas();
};

#endif