/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:54:43 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/22 16:19:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "contact.hpp"

class PhoneBook
{
	private:
		Contact phonebook[8];
		int		oldest;

		std::string trumcateField(std::string field);

	public:
		PhoneBook(void);

		void addContact(Contact contact);
		void displayContacts(void);
};

#endif