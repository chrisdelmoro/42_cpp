/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:00:46 by ccamargo          #+#    #+#             */
/*   Updated: 2024/02/11 18:11:52 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

enum file_type {
    DATABASE,
    INPUT
};

class BitcoinExchange {
private:
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    std::map<std::string, float> database;
    std::string min_date;
    std::string max_date;
    void loadDatabase(void);
    void btc(std::string date, float value);
    bool checkHeader(std::string line, file_type type);
    void checkLine(std::string line, file_type type);
    bool checkDate(std::string date, file_type type);
    bool checkValue(std::string value, file_type type);
    void trimCell(std::string &cell);

public:
    BitcoinExchange(void);
    ~BitcoinExchange(void);
    void readInput(std::string filename);

    class DatabaseLoadException : public std::exception {
        public:
            DatabaseLoadException(std::string error_message);
            virtual ~DatabaseLoadException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string error_message;
    };
    class DatabaseNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseDataException : public std::exception {
        virtual const char *what() const throw();
    };
    class InputNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputDataException : public std::exception {
        public:
            BadInputDataException(std::string line);
            virtual ~BadInputDataException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string error_message;
    };
    class BadDateException : public std::exception {
        public:
            BadDateException(std::string date);
            virtual ~BadDateException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string error_message;
    };
    class NegativeValueException : public std::exception {
        virtual const char *what() const throw();
    };
    class TooLargeValueException : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif