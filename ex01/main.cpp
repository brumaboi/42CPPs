/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:59:36 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/21 18:59:37 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to my Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    while(1)
    {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl;
            break ;
        }
        for(int i = 0; command[i]; i++)
			command[i] = std::toupper(command[i]);
        if (command == "ADD")
        {
            phoneBook.add_contact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.search_contact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Bye! Bye! We're closing shop!" << std::endl;
            break ;
        }
        else
        {
            std::cout << "Invalid command! Try using: ADD, SEARCH, EXIT" << std::endl;
        }
    }
    return 0;
}
