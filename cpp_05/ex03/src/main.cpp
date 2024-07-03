/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:25:40 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/06 21:15:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

int main(void) {
   std::cout << std::endl << "Robotomy Form" << std::endl;
    try {
        Intern intern;
        AForm *form;
        form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "Presidential Pardon Form" << std::endl;
    try {
        Intern intern;
        AForm *form;
        form = intern.makeForm("presidential pardon", "Bender");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "Shrubbery Form" << std::endl;
    try {
        Intern intern;
        AForm *form;
        form = intern.makeForm("shrubbery creation", "Bender");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "AnyForm : Error" << std::endl;
    try {
        Intern intern;
        AForm *form;
        form = intern.makeForm("any form", "Bender");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}