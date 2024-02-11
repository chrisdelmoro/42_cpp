/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:16 by ccamargo          #+#    #+#             */
/*   Updated: 2024/02/11 18:36:31 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPNEvaluator::RPNEvaluator(void) {
    return ;
}

RPNEvaluator::RPNEvaluator(RPNEvaluator const &src) {
    *this = src;
    return ;
}

RPNEvaluator::~RPNEvaluator(void) {
    return ;
}

RPNEvaluator &RPNEvaluator::operator=(RPNEvaluator const &src) {
    if (this != &src)
        *this = src;
    return (*this);
}

double RPNEvaluator::evaluate(std::string expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isOperand(token))
            operands.push(std::strtod(token.c_str(), NULL));
        else if (isOperator(token))
            try {
                doOperation(token.begin()[0]);
            } catch (std::exception &e) {
                throw EvaluateErrorException(e.what());
            }
        else
            throw EvaluateErrorException("Error");       
    }
    if (operands.size() != 1)
        throw EvaluateErrorException("Error");
    return (operands.top());
}

bool RPNEvaluator::isOperator(std::string token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    return (false);
}

bool RPNEvaluator::isOperand(std::string token) {
    int nb;

    for (std::string::iterator it = token.begin(); it != token.end(); it++) {
        if (!std::isdigit(*it))
            return (false);
    }
    nb = std::atoi(token.c_str());
    if (nb < 0 || nb > 9)
        return (false);
    return (true);        
}

void RPNEvaluator::doOperation(char op) {
    double result = 0;
    double op1 = 0;
    double op2 = 0;

    if (operands.size() < 2)
        throw EvaluateErrorException("Error");
    op2 = operands.top();
    operands.pop();
    op1 = operands.top();
    operands.pop();
    switch (op)
    {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        if (op2 == 0){
            throw EvaluateErrorException("Division by zero.");
            return ;
        }
        result = op1 / op2;
        break;
    default:
        throw EvaluateErrorException("Error");
        return ;
    }
    operands.push(result);
    return ;
}

RPNEvaluator::EvaluateErrorException::EvaluateErrorException(const std::string& message) : message(message) {
    return ;
}
const char *RPNEvaluator::EvaluateErrorException::what() const throw() {
    return (message.c_str());
}