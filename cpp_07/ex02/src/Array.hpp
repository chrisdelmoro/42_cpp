/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:05:05 by cado-car          #+#    #+#             */
/*   Updated: 2024/01/21 17:20:02 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
private:
    T*		array;
    int		size;
public:
    Array(void) : array(NULL), size(0) {}
    Array(unsigned int n) : array(new T[n]), size(n) {}
    Array(Array const& src) {
        this->array = new T[src.size];
        this->size = src.size;
        for (int i = 0; i < src.size; i++)
            this->array[i] = src.array[i];
    }
    ~Array(void) { delete [] this->array; }


    Array& operator=(Array const& src) {
        if (this != &src)
        {
            delete [] this->array;
            this->array = new T[src.size];
            this->size = src.size;
            for (int i = 0; i < src.size; i++)
                this->array[i] = src.array[i];
        }
        return (*this);
    }
    T& operator[](int index) {
        if (index < 0 || index >= this->size)
            throw OutOfBoundsException();
        return (this->array[index]);
    }


    int getSize(void) const { return (this->size); }


    class OutOfBoundsException : public std::exception {
        virtual const char* what() const throw() {
            return ("Index out of bounds.");
        }
    };
};

#endif