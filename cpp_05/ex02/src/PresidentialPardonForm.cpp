/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:24:17 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 15:36:03 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default", 1, 1), target("default") {
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source) : AForm(source), target(source.target) {
	*this = source;
	return ;
}
PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

// Operator overloads
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &source) {
	if (this == &source)
		return (*this);
	target = source.target;
	return (*this);
}

// Member functions
std::string PresidentialPardonForm::getTarget(void) const {
	return (target);
}
void		PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
