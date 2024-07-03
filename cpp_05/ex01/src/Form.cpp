/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:20:02 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 18:12:23 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name("default"), grade_to_sign(150), grade_to_execute(150) {
	return ;
}
Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else
		sign = false;
	return ;
}
Form::Form(const Form &source) : name(source.name), grade_to_sign(source.grade_to_sign), grade_to_execute(source.grade_to_execute) {
	*this = source;
	return ;
}
Form::~Form(void) {
	return ;
}

Form	&Form::operator=(const Form &other) {
	if (this == &other)
		return (*this);
	sign = other.sign;
	return (*this);
}

std::string	Form::getName(void) const {
	return (name);
}
bool		Form::getSigned(void) const {
	return (sign);
}
int			Form::getGradeToSign(void) const {
	return (grade_to_sign);
}
int			Form::getGradeToExecute(void) const {
	return (grade_to_execute);
}

void		Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > grade_to_sign)
		throw Form::GradeTooLowException();
	else
		sign = true;
	return ;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}
const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << form.getName() << " - Form grade to sign: " << form.getGradeToSign() << " / Form grade to execute: " << form.getGradeToExecute() << ".";
	return (out);
}
