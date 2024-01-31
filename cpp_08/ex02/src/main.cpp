/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 02:40:57 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/31 04:38:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
    std::cout << "Using MutantStack" << std::endl;
    MutantStack<int> mutant_stack;
    mutant_stack.push(6);
    mutant_stack.push(18);
    std::cout << mutant_stack.top() << std::endl;
    mutant_stack.pop();
    std::cout << mutant_stack.size() << std::endl;
    mutant_stack.push(4);
    mutant_stack.push(6);
    mutant_stack.push(122);
    MutantStack<int>::iterator it = mutant_stack.begin();
    MutantStack<int>::iterator ite = mutant_stack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> stack(mutant_stack);

    std::cout << std::endl;
    
    std::cout << "Using std::list" << std::endl;
    std::list<int> list_stack;
    list_stack.push_back(6);
    list_stack.push_back(18);
    std::cout << list_stack.back() << std::endl;
    list_stack.pop_back();
    std::cout << list_stack.size() << std::endl;
    list_stack.push_back(4);
    list_stack.push_back(6);
    list_stack.push_back(122);
    std::list<int>::iterator itl = list_stack.begin();
    std::list<int>::iterator itle = list_stack.end();
    ++itl;
    --itl;
    while (itl != itle) {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::list<int> list(list_stack);
    
    return (0);
}
