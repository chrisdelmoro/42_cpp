/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:24:10 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 19:56:23 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	{
		std::cout << "Shrubbery Form - All OK!" << std::endl;
		try {
			ShrubberyCreationForm form("Shrub_1");
			Bureaucrat bureaucrat("John", 1);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Shrubbery Form - Grade too low to execute!" << std::endl;
			try {
			ShrubberyCreationForm form("Shrub_2");
			Bureaucrat bureaucrat("Jane", 140);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Shrubbery Form - Grade too low to sign or execute!" << std::endl;
		try {
			ShrubberyCreationForm form("Shrub_3");
			Bureaucrat bureaucrat("Chris", 150);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "Robotomy Form - All OK!" << std::endl;
		try {
			RobotomyRequestForm form("Robo_1");
			Bureaucrat bureaucrat("John", 1);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Robotomy Form - Grade too low to execute!" << std::endl;
			try {
			RobotomyRequestForm form("Robo_2");
			Bureaucrat bureaucrat("Jane", 60);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Robotomy Form - Grade too low to sign or execute!" << std::endl;
		try {
			RobotomyRequestForm form("Robo_3");
			Bureaucrat bureaucrat("Chris", 150);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "Presidential Pardon Form - All OK!" << std::endl;
		try {
			PresidentialPardonForm form("Pres_1");
			Bureaucrat bureaucrat("John", 1);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Pesidential Pardon Form - Grade too low to execute!" << std::endl;
			try {
			PresidentialPardonForm form("Pres_2");
			Bureaucrat bureaucrat("Jane", 15);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Presidential Pardon Form - Grade too low to sign or execute!" << std::endl;
		try {
			PresidentialPardonForm form("Pres_3");
			Bureaucrat bureaucrat("Chris", 150);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
