/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:48:26 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 18:06:20 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	return ;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
	return ;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
	*this = other;
	return ;
}
Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return (*this);
	grade = other.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const {
	return (name);
}
int			Bureaucrat::getGrade(void) const {
	return (grade);
}

void		Bureaucrat::increaseGrade(void) {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}
void		Bureaucrat::decreaseGrade(void) {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << "Bureucrat " << bureaucrat.getName() << " - Grade: " << bureaucrat.getGrade() << "." << std::endl;
	return (os);
}