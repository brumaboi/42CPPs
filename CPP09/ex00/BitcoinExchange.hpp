/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:11:41 by sbruma            #+#    #+#             */
/*   Updated: 2026/05/27 14:06:19 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class BitcoinExchange {

    private:
        std::map<std::string, double> exchangeRates;
        const std::string dataFile = "data.csv";
        std::string inputFile;

    public:
        BitcoinExchange() = default;
        ~BitcoinExchange() = default;
        BitcoinExchange(const BitcoinExchange &other) = delete;
        BitcoinExchange &operator=(const BitcoinExchange &other) = delete;

        void parseDataFile();
        void processInputFile();
        void handleInputFile(const std::string &filename);
};

#endif