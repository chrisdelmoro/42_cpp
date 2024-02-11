/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:01:25 by ccamargo          #+#    #+#             */
/*   Updated: 2024/02/11 18:25:09 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <stack>

class RPNEvaluator
{
private:
    std::stack<double> operands;
    bool isOperator(std::string token);
    bool isOperand(std::string token);
    void doOperation(char op);
public:
    RPNEvaluator();
    RPNEvaluator(RPNEvaluator const &src);
    ~RPNEvaluator();
    RPNEvaluator &operator=(RPNEvaluator const &src);
    double evaluate(std::string expression);

    class EvaluateErrorException : public std::exception {
        public:
            EvaluateErrorException(const std::string& message);
            virtual ~EvaluateErrorException() throw() {};
            virtual const char *what() const throw();
        private:
            std::string message;
    };
};

#endif