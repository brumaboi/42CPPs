/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:11:41 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/18 13:11:41 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

class BitcoinExchange {

    private:
        std::map<std::string, double> exchangeRates;
        const std::string dataFile = "data.csv";
        std::string inputFile;

        bool isValidDate(const std::string &date) const;
        bool isValidInput(const std::string &line) const;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other) = delete;
        BitcoinExchange &operator=(const BitcoinExchange &other) = delete;

        void parseDataFile();
        void processDataFile();
        void handleInputFile(const std::string &filename);
};