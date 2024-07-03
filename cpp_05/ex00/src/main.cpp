/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:00:40 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 16:19:26 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "Creating a John bureaucrat with max grade(1)" << std::endl;
	try {
		Bureaucrat b1("John", 1);
		std::cout << b1;
		std::cout << "Decreasing " << b1.getName() << "\'s grade by 1." << std::endl;
		b1.decreaseGrade();
		std::cout << b1;
		std::cout << "Increasing " << b1.getName() << "\'s grade by 1." << std::endl;
		b1.increaseGrade();
		std::cout << b1;
		std::cout << "Increasing " << b1.getName() << "\'s grade by 1." << std::endl;
		b1.increaseGrade();
		std::cout << b1;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Creating a Jane bureaucrat with minimum grade(150)" << std::endl;
	try {
		Bureaucrat b2("Jane", 150);
		std::cout << b2;
		std::cout << "Increasing " << b2.getName() << "\'s grade by 1." << std::endl;
		b2.increaseGrade();
		std::cout << b2;
		std::cout << "Decreasing " << b2.getName() << "\'s grade by 1." << std::endl;
		b2.decreaseGrade();
		std::cout << b2;
		std::cout << "Decreasing " << b2.getName() << "\'s grade by 1." << std::endl;
		b2.decreaseGrade();
		std::cout << b2;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Creating a John bureaucrat with an invalid grade(0)" << std::endl;
	try {
		Bureaucrat b3("John", 0);
		std::cout << b3;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Creating a Jane bureaucrat with en invalid grade(151)" << std::endl;
	try {
		Bureaucrat b4("Jane", 151);
		std::cout << b4;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}