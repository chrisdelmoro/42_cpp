/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 02:40:46 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/31 03:55:20 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>
# include <stdexcept>

class Span {
private:
    unsigned int        n;
    std::vector<int>    vec;
public:
    Span(unsigned int n);
    Span(const Span &source);
    ~Span();

    Span &operator=(const Span &source);

    void    addNumber(int n);
    int     shortestSpan(void);
    int     longestSpan(void);
    
    template <typename T>
    void    addRange(T begin, T end) {
        if (this->vec.size() + std::distance(begin, end) > this->n) {
            throw FullContainerException();
        }
        this->vec.insert(this->vec.end(), begin, end);
        return ;
    }

    unsigned int        getN(void) const;
    std::vector<int>    getVec(void) const;

    class FullContainerException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class NotEnoughElementsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif