/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:45:06 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/21 17:00:47 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void print(T const &i) {
    std::cout << i << std::endl;
}

#endif