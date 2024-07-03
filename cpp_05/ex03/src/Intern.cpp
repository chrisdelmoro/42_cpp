/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:25:27 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 21:08:28 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
    form_types[ROBOTOMY_REQUEST] = "robotomy request";
    form_types[PRESIDENTIAL_PARDON] = "presidential pardon";
    form_types[SHRUBBERY_CREATION] = "shrubbery creation";
    return ;
}
Intern::~Intern(void) {
    return ;
}

AForm* Intern::makeForm(std::string name, std::string target) {
    AForm*  form = NULL;
    int     form_type = -1;

    while (++form_type < 3)
        if (name == form_types[form_type])
            break ;

    switch (form_type) {
        case ROBOTOMY_REQUEST:
            form = new RobotomyRequestForm(target);
            break;
        case PRESIDENTIAL_PARDON:
            form = new PresidentialPardonForm(target);
            break;
        case SHRUBBERY_CREATION:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            throw Intern::FormNotFoundException();
            return (NULL);
    }
    std::cout << "Intern creates " << form->getName() << "." << std::endl;
    return (form);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return ("Form could not be created. Select a valid form to use.");
}