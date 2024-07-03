/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:45:13 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/21 17:01:02 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {
    int a[] = {1, 2, 3, 4, 5};
    std::string b[] = {"A", "B", "C", "D", "E"};

    std::cout << "Number:" << std::endl;
    ::iter(a, 5, print);
    std::cout << std::endl;
    std::cout << "Strings:" << std::endl;
    ::iter(b, 5, print);
    return (0);
}
