/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:20:10 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 15:08:12 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool				sign;
	int const			grade_to_sign;
	int const			grade_to_execute;
public:
	Form(void);
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &source);
	~Form(void);
	Form	&operator=(const Form &other);

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;

	void		beSigned(Bureaucrat &bureaucrat);	

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif