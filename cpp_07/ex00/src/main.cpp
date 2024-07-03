/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:18:27 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/21 16:33:38 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.hpp"

int main( void ) {
    int a = 5;
    int b = 10;

    ::swap(a, b);
    std::cout << "Swaped Numbers: a = " << a << ", b = " << b << std::endl;
    std::cout << "Min = " << ::min( a, b ) << std::endl;
    std::cout << "MAx = " << ::max( a, b ) << std::endl;

    std::string c = "Arthur";
    std::string d = "Marvin";

    ::swap(c, d);
    std::cout << "Swaped Strings: c = " << c << ", d = " << d << std::endl;
    std::cout << "Min = " << ::min( c, d ) << std::endl;
    std::cout << "Max = " << ::max( c, d ) << std::endl;

    return 0;
}
