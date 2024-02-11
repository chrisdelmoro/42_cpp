/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:08 by ccamargo          #+#    #+#             */
/*   Updated: 2024/02/11 18:01:11 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    RPNEvaluator rpn;

    if (argc != 2) {
        std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
        return (1);
    }
    try {
        std::cout << rpn.evaluate(argv[1]) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}