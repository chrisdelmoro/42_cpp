/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:07:02 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/21 18:02:16 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact handle_add(void)
{
	Contact contact;
	std::string buffer = "";

	while (buffer == "")
	{
		std::cout << "Enter contact first name >> ";
		std::getline(std::cin, buffer);
		if (buffer == "")
			std::cout << EMPTY_FIELD << std::endl;
	}
	contact.setFirstName(buffer);

	buffer = "";
	while (buffer == "")
	{
		std::cout << "Enter contact last name >> ";
		std::getline(std::cin, buffer);
		if (buffer == "")
			std::cout << EMPTY_FIELD << std::endl;
	}
	contact.setLastName(buffer);

	buffer = "";
	while (buffer == "")
	{
		std::cout << "Enter contact nickname >> ";
		std::getline(std::cin, buffer);
		if (buffer == "")
			std::cout << EMPTY_FIELD << std::endl;
	}
	contact.setNickname(buffer);

	buffer = "";
	while (buffer == "")
	{
		std::cout << "Enter contact phone number >> ";
		std::getline(std::cin, buffer);
		if (buffer == "")
			std::cout << EMPTY_FIELD << std::endl;
	}
	contact.setPhone(buffer);

	buffer = "";
	while (buffer == "")
	{
		std::cout << "Enter contact darkest secret >> ";
		std::getline(std::cin, buffer);
		if (buffer == "")
			std::cout << EMPTY_FIELD << std::endl;
	}
	contact.setSecret(buffer);

	return contact;
}

void handle_search(void)
{
	std::cout << "SEARCHING! SEARCHING!" << std::endl;
}

int main(void)
{
	std::string command = "";
	Contact test;

	std::cout << "Welcome to the awesome crappy phonebook!" << std::endl;
	std::cout << "You can ADD contacts (up to eight) and also SEARCH for en existing contact!" << std::endl;
	std::cout << "When you are done, type EXIT to close the software." << std::endl;
	while (command != "EXIT")
	{
		std::cout << "Option >> ";
		std::getline(std::cin, command);
		if (command != "ADD" && command != "SEARCH" && command != "EXIT")
		{
			std::cout << "Only ADD, SEARCH and EXIT are valid commands!" << std::endl;
			continue;
		}
		if (command == "ADD")
		{
			test = handle_add();
			std::cout << test.getFirstName() << std::endl;
		}
		if (command == "SEARCH")
			handle_search();
	}
	return 0;
}