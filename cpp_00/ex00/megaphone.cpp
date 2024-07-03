/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:28:16 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/20 23:56:39 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string capitalize(std::string attr)
{
	for (size_t j = 0; j < attr.length(); j++)
		attr[j] = std::toupper(attr[j]);
	return attr;
}

int	main(int argc, const char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; i < (size_t) argc; i++)
		{
			std::string attr(argv[i]);
			attr = capitalize(attr);
			std::cout << attr;
		}
		std::cout << std::endl;
	}
	return 0;
}