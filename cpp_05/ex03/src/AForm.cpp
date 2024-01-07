/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:23:38 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 15:29:38 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
AForm::AForm(void) : name("default"), sign(false), gradeToSign(1), gradeToExecute(1) {
	return ;
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}
AForm::AForm(const AForm &source) : name(source.name), sign(source.sign), gradeToSign(source.gradeToSign), gradeToExecute(source.gradeToExecute) {
	*this = source;
	return ;
}
AForm::~AForm(void) {
	return ;
}

// Operator overloads
AForm	&AForm::operator=(const AForm &source) {
	if (this == &source)
		return (*this);
	sign = source.sign;
	return (*this);
}

// Member functions
std::string AForm::getName(void) const {
	return (name);
}
bool		AForm::getSigned(void) const {
	return (sign);
}
int			AForm::getGradeToSign(void) const {
	return (gradeToSign);
}
int			AForm::getGradeToExecute(void) const {
	return (gradeToExecute);
}

// Sign form
void		AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	else
		sign = true;
	return ;
}

// Exception classes
const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}
const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}
const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed!");
}

// Overload << operator for output
std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() << " is ";
	if (form.getSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (os);
}
