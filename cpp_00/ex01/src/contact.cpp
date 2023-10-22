/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:10:03 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/21 19:30:30 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

Contact::Contact(void)
{
	this->index = -1;
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone = "";
	this->secret = "";
}

void Contact::setIndex(int index)
{
	this->index = index;
}

void Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::setPhone(std::string phone)
{
	this->phone = phone;
}

void Contact::setSecret(std::string secret)
{
	this->secret = secret;
}


int Contact::getIndex(void)
{
	return this->index;
}

std::string Contact::getFirstName(void)
{
	return this->first_name;
}

std::string Contact::getLastName(void)
{
	return this->last_name;
}

std::string Contact::getNickname(void)
{
	return this->nickname;
}

std::string Contact::getPhone(void)
{
	return this->phone;
}

std::string Contact::getSecret(void)
{
	return this->secret;
}