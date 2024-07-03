/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:33:44 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 14:44:55 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
    return ;
}
ScalarConverter::ScalarConverter(const ScalarConverter &source) {
    *this = source;
    return ;
}
ScalarConverter::~ScalarConverter(void) {
    return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) {
	if (this == &source)
		return (*this);
    *this = source;
	return (*this);
}

void ScalarConverter::convert(const std::string &literal) {
    try {
        int type = getType(literal);
        switch (type)
        {
        case 0:
            toChar(literal);
            break;
        case 1:
            toInt(literal);
            break;
        case 2:
            toFloat(literal);
            break;
        case 3:
            toDouble(literal);
            break;
        default:
            throw InvalidLiteralException();
            break;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return ;    
}

int ScalarConverter::getType(const std::string &literal) {
    if (isChar(literal))
        return (0);
    if (isInt(literal))
        return (1);
    if (isFloat(literal))
        return (2);
    if (isDouble(literal))
        return (3);
    throw InvalidLiteralException();
}

bool ScalarConverter::isChar(const std::string &literal) {
    size_t  len = literal.length();
    
    if (literal[0] == '\'' && literal[len - 1] == '\'') {
        if (len == 3 && (literal[1] > 31 && literal[1] < 127))
            return (true);
        if (len == 4 && literal[1] == '\\')
            if (literal[2] == 'n' || literal[2] == 't' || literal[2] == 'v' || literal[2] == 'b' || literal[2] == 'r' || literal[2] == 'f' || literal[2] == 'a' || literal[2] == '\\' || literal[2] == '0' || literal[2] == 'e')
                return (true);
        if (len > 4 && literal[1] == '\\') {
			for (size_t i = 2; i < len - 1; i++)
				if (literal[i] != 'x' && !std::isxdigit(literal[i]))
					return (false);
			return (true);
		}
    }
    return (false);
}

bool ScalarConverter::isInt(const std::string &literal) {
    size_t  len = literal.length();
    long    nb;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return (true);
    for (size_t i = 0; i < len; i++) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            i++;
        if (!std::isdigit(literal[i]))
            return (false);
    }
    nb = std::strtol(literal.c_str(), NULL, 10);
    if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
        return (false);
    return (true);
}
bool ScalarConverter::isFloat(const std::string &literal) {
    size_t  len = literal.length();
    bool    dot = false;
    size_t  i = 0;
    double  nb;

    if (literal.substr(i, len) == "nanf")
        return (true);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal.substr(i, len) == "inff")
        return (true);
    if (literal[len - 1] != 'f')
        return (false);
    for (; i < len - 1; i++) {
        if (literal[i] == '.' && !dot)
            dot = true;
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    if (!dot)
        return (false);
    nb = std::strtod(literal.c_str(), NULL);
    if (nb > std::numeric_limits<float>::max() || nb < -std::numeric_limits<float>::max())
        return (false);
    return (true);
}
bool ScalarConverter::isDouble(const std::string &literal) {
    size_t  len = literal.length();
    size_t  i = 0;
    bool    dot = false;
    double  nb;

    if (literal.substr(i, len) == "nan")
        return (true);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal.substr(i, len) == "inf")
        return (true);
    for (; i < len; i++) {
        if (literal[i] == '.' && !dot)
            dot = true;
        else if (literal[i] < '0' || literal[i] > '9') {
            return (false);
        }
    }
    if (!dot)
        return (false);
    nb = std::strtod(literal.c_str(), NULL);
    if (nb > std::numeric_limits<double>::max() || nb < -std::numeric_limits<double>::max())
        return (false);
    return (true);
}

void ScalarConverter::toChar(const std::string &literal) {
    size_t  len = literal.length();

    std::cout << "Char: ";
    try {
        if (len > 3 || literal[1] == 32)
            throw NonDisplayableException();
        std::cout << "'" << static_cast<char>(literal[1]) << "'" << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return ;
}
void ScalarConverter::toInt(const std::string &literal) {
    int nb;

    std::cout << "Int: ";
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        nb = static_cast<int>(literal[0]);
    else {
        nb = std::atoi(literal.c_str());
    }
    std::cout << nb << std::endl;
    return ;
}
void ScalarConverter::toFloat(const std::string &literal) {
    float   nb;
    int     len = literal.length();
    int     sign = 1;
    int     i = 0;
    
    if (literal.substr(i, len) == "nanf")
        nb = std::numeric_limits<float>::quiet_NaN();
    else {
        if (literal[i] == '-' || literal[i] == '+') {
            if (literal[i] == '-')
                sign *= -1;
            i++;
        }
        if (literal.substr(i, len) == "inff")
            nb = sign * std::numeric_limits<float>::infinity();
        else
            nb = std::atof(literal.c_str());
    }
    std::cout << "Float: " << nb << "f" << std::endl;
    return ;
}
void ScalarConverter::toDouble(const std::string &literal) {
    double  nb;
    int     len = literal.length();
    int     sign = 1;
    int     i = 0;
    
    if (literal.substr(i, len) == "nan")
        nb = std::numeric_limits<double>::quiet_NaN();
    else {
        if (literal[i] == '-' || literal[i] == '+') {
            if (literal[i] == '-')
                sign *= -1;
            i++;
        }
        if (literal.substr(i, len) == "inf")
            nb = sign * std::numeric_limits<double>::infinity();
        else
            nb = std::strtod(literal.c_str(), NULL);
    }
    std::cout << "Double: " << nb << std::endl;
    return ;
}

const char *ScalarConverter::InvalidLiteralException::what() const throw() {
    return ("Invalid literal");
}
const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return ("Non displayable");
}