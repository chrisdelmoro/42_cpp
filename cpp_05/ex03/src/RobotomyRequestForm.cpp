/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:24:30 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 20:28:40 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default", 1, 1), target("default") {
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), target(source.target) {
	*this = source;
	return ;
}
RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

// Operator overloads
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
	if (this == &source)
		return (*this);
	target = source.target;
	return (*this);
}

// Member functions
std::string RobotomyRequestForm::getTarget(void) const {
	return (target);
}
void		RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::cout << "Drill Drill Drill..." << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << target << " robotomization failed." << std::endl;
}
