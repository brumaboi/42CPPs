/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:11:33 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/18 13:11:33 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool isValidDate(const std::string &date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue ;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    if (year < 1)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[2] = 29;
    if (day > daysInMonth[month])
        return false;
    return true;
}

void BitcoinExchange::processInputFile() {
    std::ifstream file(inputFile);
    if (!file.is_open())
        throw std::runtime_error("could not open file: " + inputFile);
    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            if (line.find("date") != std::string::npos)
                continue ;
        }
        if (line.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);
        if (!::isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue ;
        }
        double value;
        try {
            std::size_t idx;
            value = std::stod(valueStr, &idx);
            if (idx != valueStr.length()) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue ;
            }
        } catch (...) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue ;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue ;
        }
        std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);
        if (it != exchangeRates.end() && it->first == date) {
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        } else {
            if (it == exchangeRates.begin()) {
                std::cerr << "Error: date too early => " << date << std::endl;
                continue ;
            }
            --it;
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::parseDataFile() {
    std::ifstream file(dataFile);
    if (!file.is_open())
        throw std::runtime_error("could not open file: " + dataFile);
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue ;
        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);
        try {
            double rate = std::stod(rateStr);
            exchangeRates[date] = rate;
        } catch (...) {
            continue ;
        }
    }
    file.close();
}

void BitcoinExchange::handleInputFile(const std::string &filename) {
    inputFile = filename;
    parseDataFile();
    processInputFile();
}
