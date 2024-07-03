/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:33:37 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 14:18:57 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Incorrect usage of application!" << std::endl;
        std::cout << "Correct usage: ./ex00 \"<literal>\"" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}