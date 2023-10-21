/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:44:20 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/21 18:16:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

# define EMPTY_FIELD "No field can be empty!"

class Contact
{
	private:
		int			index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;

	public:
		Contact(void);

		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickname(std::string nickname);
		void setPhone(std::string phone);
		void setSecret(std::string secret);

		std::string getFirstName(void);
};

#endif