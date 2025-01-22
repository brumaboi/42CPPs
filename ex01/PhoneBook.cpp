/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:59:45 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/21 18:59:48 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
    : _index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
    size_t i;
    std::string _first_name, _last_name, _nickname, _phone_number, _darkest_secret;

    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, _first_name))
        return ;
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, _last_name))
        return ;
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, _nickname))
        return ;
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, _phone_number))
        return ;
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, _darkest_secret))
        return ;
    i = _index % MAX_SIZE;
    _contacts[i].set_first_name(_first_name);
    _contacts[i].set_last_name(_last_name);
    _contacts[i].set_nickname(_nickname);
    _contacts[i].set_phone_number(_phone_number);
    _contacts[i].set_darkest_secret(_darkest_secret);
    _index++;
    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::print_details(size_t index) const
{
    const Contact &contact = _contacts[index];

    std::cout << "First Name: " << contact.get_first_name() << std::endl;
    std::cout << "Last Name: " << contact.get_last_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact()
{

}