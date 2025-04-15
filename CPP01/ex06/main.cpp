/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:00:45 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 19:00:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;

	if (argc != 2)
		return (std::cout << "Usage: ./harlFilter <level>" << std::endl, 1);
	level = argv[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
		return (std::cout << "Error: Invalid level. Valid levels are: DEBUG, INFO, WARNING, ERROR" << std::endl, 1);
	harl.complain(level);
	std::cout << std::endl;
    return (0);
}