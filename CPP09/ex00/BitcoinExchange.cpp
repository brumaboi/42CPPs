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

//TODO: Implement the methods declared in BitcoinExchange.hpp

void BitcoinExchange::handleInputFile(const std::string &filename) {
    inputFile = filename;
    parseDataFile();
    processInputFile();
}
