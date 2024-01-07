/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:23:57 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 19:51:05 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name) {
	*this = source;
	return ;
}
Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source) {
	if (this == &source)
		return (*this);
	grade = source.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const {
	return (name);
}
int			Bureaucrat::getGrade(void) const {
	return (grade);
}

void		Bureaucrat::incrementGrade(void) {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}
void		Bureaucrat::decrementGrade(void) {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void		Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}