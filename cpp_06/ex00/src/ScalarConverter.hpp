/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:33:50 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 14:45:01 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <limits>
# include <cfloat>
# include <string.h>

class ScalarConverter {

private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &source);
    ~ScalarConverter(void);
    ScalarConverter &operator=(const ScalarConverter &source);
    static int getType(const std::string &literal);
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);
    static void toChar(const std::string &literal);
    static void toInt(const std::string &literal);
    static void toFloat(const std::string &literal);
    static void toDouble(const std::string &literal);

public:
    static void convert(const std::string &literal);
    class InvalidLiteralException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class NonDisplayableException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif