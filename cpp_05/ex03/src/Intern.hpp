/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:25:34 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 15:49:05 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

enum FormType {
    ROBOTOMY_REQUEST,
    PRESIDENTIAL_PARDON,
    SHRUBBERY_CREATION
};

class Intern
{
private:
    std::string   form_types[3];
public:
    Intern();
    ~Intern();
    AForm* makeForm(std::string name, std::string target);

    class FormNotFoundException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif