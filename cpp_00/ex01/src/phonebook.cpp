/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:58:47 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/21 21:03:50 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->oldest = 0;
	for (int i = 0; i <= 7; i++)
		this->phonebook[i].setIndex(-1);
}

void PhoneBook::addContact(Contact contact)
{
	contact.setIndex(this->oldest);
	this->phonebook[this->oldest] = contact;
	this->oldest++;
}

void PhoneBook::displayContacts(void)
{
	int index_choise;

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i <= 7; i++)
	{
		if (phonebook[i].getIndex() != -1)
		{
			std::cout << phonebook[i].getIndex() + 1 << std::endl;
			std::cout << phonebook[i].getFirstName() << std::endl;
			std::cout << phonebook[i].getLastName() << std::endl;
			std::cout << phonebook[i].getNickname() << std::endl;
		}
	}
	std::cout << "Type the index of the contact you wish to access >> ";
	std::cin >> index_choise;
	index_choise--;
	if (phonebook[index_choise].getIndex() != -1 && index_choise >= 0 && index_choise <= 7)
	{
		std::cout << phonebook[index_choise].getIndex() + 1 << std::endl;
		std::cout << phonebook[index_choise].getFirstName() << std::endl;
		std::cout << phonebook[index_choise].getLastName() << std::endl;
		std::cout << phonebook[index_choise].getNickname() << std::endl;
		std::cout << phonebook[index_choise].getPhone() << std::endl;
		std::cout << phonebook[index_choise].getSecret() << std::endl;
	}
	else
	{
		std::cout << "Contact with that index does not exist!" << std::endl;
	}
}