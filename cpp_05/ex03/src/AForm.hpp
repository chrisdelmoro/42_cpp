/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:23:50 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 15:27:47 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
private:
	std::string const	name;
	bool				sign;
	int const			gradeToSign;
	int const			gradeToExecute;
public:
	AForm(void);
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &source);
	virtual ~AForm(void);

	AForm	&operator=(const AForm &other);

	std::string getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;
	void		beSigned(Bureaucrat &bureaucrat);

	virtual void		execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif