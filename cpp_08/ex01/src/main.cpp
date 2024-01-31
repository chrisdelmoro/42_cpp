/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 02:40:34 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/31 03:57:33 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    std::cout << std::endl;

    std::cout << "10000 elements" << std::endl;
    Span sp3 = Span(10000);
    std::srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        sp3.addNumber(std::rand() % 10000);
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;    

    std::cout << std::endl;

    std::cout << "100000 elements" << std::endl;
    Span sp4 = Span(100000);
    std::list<int> lst;
    for (int i = 0; i < 100000; i++)
        lst.push_back(std::rand() % 100000);
    sp4.addRange(lst.begin(), lst.end());
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;
    return (0);
}
