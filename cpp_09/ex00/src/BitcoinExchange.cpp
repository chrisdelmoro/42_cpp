/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:00:55 by ccamargo          #+#    #+#             */
/*   Updated: 2024/02/11 18:12:52 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : database() {
    try {
        loadDatabase();
    } catch (std::exception &e) {
        throw DatabaseLoadException(e.what());
    }
    min_date = database.begin()->first;
    max_date = database.rbegin()->first;
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    this->database = src.database;
    return ;
}

BitcoinExchange::~BitcoinExchange(void) {
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    this->database = src.database;
    return (*this);
}

void BitcoinExchange::loadDatabase(void) {
    std::string filename = "data.csv";
    std::ifstream file(filename.c_str());
    std::string line;
    std::string date;
    std::string value;
    float fvalue;

    if (!file.is_open()) {
        throw DatabaseNotFoundException();
        return ;
    }
    std::getline(file, line);
    if (!checkHeader(line, DATABASE))
        throw BadDatabaseFormatException();
    else {
        while (std::getline(file, line)) {
            try {
                checkLine(line, DATABASE);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                throw BadDatabaseFormatException();
                break ;
            }
            date = line.substr(0, line.find(','));
            value = line.substr(line.find(',') + 1);
            fvalue = std::atof(value.c_str());
            database[date] = fvalue;
        }
    }
    file.close();
    return ;
}

void BitcoinExchange::readInput(std::string filename) {    
    std::ifstream file(filename.c_str());
    std::string line;
    std::string date;
    std::string value;
    float fvalue;

    if (!file.is_open())
        throw InputNotFoundException();
    std::getline(file, line);
    if (!checkHeader(line, INPUT))
        throw BadInputFormatException();
    while (std::getline(file, line)) {
        try {
            checkLine(line, INPUT);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            continue ;
        }
        date = line.substr(0, line.find('|'));
        value = line.substr(line.find('|') + 1);
        fvalue = std::atof(value.c_str());
        btc(date, fvalue);
    }
}

void BitcoinExchange::btc(std::string date, float value) {
    std::map<std::string, float>::iterator it = database.find(date);
    std::string last_date;
    float last_value;

    if (it != database.end()) {
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        return ;
    }
    for (it = database.begin(); it != database.end(); it++) {
        if (it->first > date)
            break ;
        last_date = it->first;
        last_value = it->second;
    }
    std::cout << date << " => " << value << " = " << value * last_value << std::endl;
}

bool BitcoinExchange::checkHeader(std::string header, file_type type) {
    char        delimiter = type == DATABASE ? ',' : '|';
    std::string column1 = "date";
    std::string column2 = type == DATABASE ? "exchange_rate" : "value";

    if (std::count(header.begin(), header.end(), delimiter) != 1)
        return (false);
    std::string header1 = header.substr(0, header.find(delimiter));
    std::string header2 = header.substr(header.find(delimiter) + 1);
    trimCell(header1);
    trimCell(header2);
    trimCell(column1);
    trimCell(column2);
    if (header1 != column1 || header2 != column2)
        return (false);
    return (true);
}

void BitcoinExchange::checkLine(std::string line, file_type type) {
    char        delimiter = type == DATABASE ? ',' : '|';
    
    int delimiter_count = std::count(line.begin(), line.end(), delimiter);
    if (delimiter_count != 1) {
        throw BadInputDataException(line);
        return ;
    }
    std::string date = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter) + 1);
    trimCell(date);
    trimCell(value);
    if (!date.length() || !value.length())
        throw BadInputDataException(line);
    else if (!checkDate(date, type))
        throw BadDateException(date);
    else if (!checkValue(value, type)) {
        if (std::atof(value.c_str()) < 0)
            throw NegativeValueException();
        else if (std::atof(value.c_str()) > 1000)
            throw TooLargeValueException();
        else
            throw BadInputDataException(line);
    }
    return ;
}

bool BitcoinExchange::checkDate(std::string date, file_type type) {
    if (date.length() != 10)
        return (false);
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return (false);
        } else if (!std::isdigit(date[i]))
            return (false);
    }
    if (type == INPUT && date < min_date)
        return (false);
    int month = std::atoi(date.substr(5, 2).c_str());
    if (month < 1 || month > 12)
        return (false);
    int day = std::atoi(date.substr(8, 2).c_str());
    if (day < 1)
        return (false);
    if (month == 2 && day > 29)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

bool BitcoinExchange::checkValue(std::string value, file_type type) {
    bool dot = false;

    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == '.') {
            if (dot)
                return (false);
            dot = true;
        }
        else if (!std::isdigit(value[i]))
            return (false);
    }
    if (type == INPUT && std::atof(value.c_str()) > 1000)
        return (false);
    else if (type == INPUT && std::atof(value.c_str()) < 0)
        return (false);
    return (true);
}

void BitcoinExchange::trimCell(std::string &cell) {
    size_t start = cell.find_first_not_of(" \t");
    size_t end = cell.find_last_not_of(" \t");
    if (start == std::string::npos)
        cell = "";
    else
        cell = cell.substr(start, end - start + 1);    
}

BitcoinExchange::DatabaseLoadException::DatabaseLoadException(std::string error_message) : error_message(error_message) {
    return ;
}
const char *BitcoinExchange::DatabaseLoadException::what() const throw() {
    return (this->error_message.c_str());
}

const char *BitcoinExchange::DatabaseNotFoundException::what() const throw() {
    return ("Database file not found. Please, make sure there is a `data.csv` file in the root of your repository.");
}

const char *BitcoinExchange::BadDatabaseFormatException::what() const throw() {
    return ("Bad format in Database file. Please, make sure your database is a .csv with two columns: `date,exchange_rate`");
}

const char *BitcoinExchange::BadDatabaseDataException::what() const throw() {
    return ("Bad data in Database file. Please, make sure your databese is filled correctly.");
}

const char *BitcoinExchange::InputNotFoundException::what() const throw() {
    return ("Input file not found. Please, make sure your input file exists and has the right permissions.");
}

const char *BitcoinExchange::BadInputFormatException::what() const throw() {
    return ("Bad format in Input file. Please, make sure your input is a .txt with two columns: `date|value`");
}

BitcoinExchange::BadInputDataException::BadInputDataException(std::string line) : error_message("bad input => " + line) {
    return ;
}
const char *BitcoinExchange::BadInputDataException::what() const throw() {
    return (this->error_message.c_str());
}

BitcoinExchange::BadDateException::BadDateException(std::string date) : error_message("bad date => " + date) {
    return ;
}
const char *BitcoinExchange::BadDateException::what() const throw() {
    return (this->error_message.c_str());
}

const char *BitcoinExchange::NegativeValueException::what() const throw() {
    return ("not a positive number.");
}

const char *BitcoinExchange::TooLargeValueException::what() const throw() {
    return ("too large a number.");
}