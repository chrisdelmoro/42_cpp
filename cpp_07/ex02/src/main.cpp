/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:07:20 by cado-car          #+#    #+#             */
/*   Updated: 2024/01/21 18:08:48 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    std::cout << "Empty Array:" << std::endl;
    Array<int> empty;
    try {
        std::cout << "Trying to access index 0: " << empty[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Array of 5 integers" << std::endl;
    Array<int> five(5);
    std::cout << "Size: " << five.getSize() << std::endl;
    for (int i = 0; i < five.getSize(); i++)
        five[i] = i;
    for (int i = 0; i < five.getSize(); i++)
        std::cout << "five[" << i << "]: " << five[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Array of 5 strings" << std::endl;
    Array<std::string> strings(5);
    std::cout << "Size: " << strings.getSize() << std::endl;
    strings[0] = "Hello";
    strings[1] = "World!";
    strings[2] = "How";
    strings[3] = "are";
    strings[4] = "you?";
    for (int i = 0; i < strings.getSize(); i++)
        std::cout << "strings[" << i << "]: " << strings[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Copy Constructor" << std::endl;
    Array<std::string> copy(strings);
    std::cout << "Size: " << copy.getSize() << std::endl;
    for (int i = 0; i < copy.getSize(); i++)
        std::cout << "copy[" << i << "]: " << copy[i] << std::endl;
    std::cout << "Getting the arrays locations" << std::endl;
    std::cout << "strings: " << &strings << std::endl;
    std::cout << "copy: " << &copy << std::endl;
    std::cout << std::endl;

    std::cout << "Assignment Operator" << std::endl;
    Array<std::string> assign;
    assign = strings;
    std::cout << "Size: " << assign.getSize() << std::endl;
    for (int i = 0; i < assign.getSize(); i++)
        std::cout << "assign[" << i << "]: " << assign[i] << std::endl;
    std::cout << "Getting the arrays locations" << std::endl;
    std::cout << "strings: " << &strings << std::endl;
    std::cout << "assign: " << &assign << std::endl;
    std::cout << std::endl;
    
    std::cout << "Out of bounds exception" << std::endl;
    Array<int> out(5);
    std::cout << "Size: " << out.getSize() << std::endl;
    for (int i = 0; i < out.getSize(); i++)
        out[i] = i;
    for (int i = 0; i < out.getSize(); i++)
        std::cout << "out[" << i << "]: " << out[i] << std::endl;
    try {
        std::cout << "Trying to access index 5: " << out[5] << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}
