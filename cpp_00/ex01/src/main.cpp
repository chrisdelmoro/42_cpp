/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:07:02 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/22 19:46:30 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

std::string validate_input(std::string msg)
{
	std::string buffer = "";
	bool flag = 0;

	while (buffer == "")
	{
		std::cout << msg;
		std::getline(std::cin, buffer);
		for (size_t i = 0; i < buffer.length(); i++)
        {
            if(!std::isspace(static_cast<unsigned char>(buffer[i])))
				flag = 1;
        }
		if (flag == 0 || buffer == "")
		{
			std::cout << EMPTY_FIELD << std::endl;
			buffer = "";
		}
    }
	return buffer;
}

Contact handle_add(void)
{
	Contact contact;

	contact.setFirstName(validate_input("Enter contact's first name >> "));
	contact.setLastName(validate_input("Enter contact's last name >> "));
	contact.setNickname(validate_input("Enter contact's nickname >> "));
	contact.setPhone(validate_input("Enter contact's phone number >> "));
	contact.setSecret(validate_input("Enter contact's darkest secret >> "));

	return contact;
}

void handle_search(PhoneBook phonebook)
{
	phonebook.displayContacts();
}

int main(void)
{
	std::string command = "";
	Contact test;
	PhoneBook phonebook;

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
			phonebook.addContact(handle_add());
		if (command == "SEARCH")
			handle_search(phonebook);
	}
	return 0;
}