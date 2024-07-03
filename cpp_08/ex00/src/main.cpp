/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 02:40:22 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/31 03:16:39 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::cout << "Container with a list of ints" << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i);
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::cout << "Searching for 2: ";
        std::cout << *easyfind(lst, 2) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Searching for 7: ";
        std::cout << *easyfind(lst, 7) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Container with a vector of ints" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i);
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::cout << "Searching for 2: ";
        std::cout << *easyfind(vec, 2) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Searching for 15: ";
        std::cout << *easyfind(vec, 15) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Container with a deque of ints" << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 5; i++)
        deq.push_back(i);
    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::cout << "Searching for 2: ";
        std::cout << *easyfind(deq, 2) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Searching for 10: ";
        std::cout << *easyfind(deq, 10) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
  
    return (0);
}
