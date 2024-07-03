/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:35:25 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 15:30:58 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "identify.hpp"

int main(void)
{
    std::srand(std::time(NULL));
    Base *base = generate();
    std::cout << "Base class pointed: ";
    identify(base);
    std::cout << "Base class referenced: ";
    identify(*base);
    delete base;
    return (0);
}