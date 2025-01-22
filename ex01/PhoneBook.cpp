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

bool is_num(const std::string &str)
{
    size_t i;

    if(str.empty())
        return false;
    i = 0;
    while (i < str.size())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool is_alpha(const std::string &str)
{
    size_t i;

    if(str.empty())
        return false;
    i = 0;
    while (i < str.size())
    {
        if (!std::isalpha(str[i]))
            return false;
        i++;
    }
    return true;
}

void PhoneBook::add_contact()
{
    size_t i;
    std::string _first_name, _last_name, _nickname, _phone_number, _darkest_secret;

    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, _first_name))
        return ;
    if (!is_alpha(_first_name) || _first_name.empty())
    {
        std::cout << "First name must be alphabetical and not empty!" << std::endl;
        return ;
    }
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, _last_name))
        return ;
    if (!is_alpha(_last_name) || _last_name.empty())
    {
        std::cout << "Last name must be alphabetical and not empty!" << std::endl;
        return ;
    }
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, _nickname))
        return ;
    if (_nickname.empty())
    {
        std::cout << "Nickname must not be empty!" << std::endl;
        return ;
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, _phone_number))
        return ;
    if (!is_num(_phone_number) || _phone_number.empty())
    {
        std::cout << "Phone number must be numerical and not empty!" << std::endl;
        return ;
    }
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, _darkest_secret))
        return ;
    if (_darkest_secret.empty())
    {
        std::cout << "Darkest secret must not be empty!" << std::endl;
        return ;
    }
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

static std::string too_long(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::print_list() const
{
    size_t contact_i;
    size_t i;

    contact_i = (_index < MAX_SIZE) ? _index : MAX_SIZE;
    std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10);
    std::cout << "First Name" << "|" << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    i = 0;
    while(i < contact_i)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10) << too_long(_contacts[i].get_first_name());
        std::cout<< "|" << std::setw(10) << too_long(_contacts[i].get_last_name());
        std::cout << "|" << std::setw(10) << too_long(_contacts[i].get_nickname()) << "|" << std::endl;
        i++;
    }
}

void PhoneBook::search_contact()
{
    int i;
    int the_index;

    i = (_index < MAX_SIZE) ? _index : MAX_SIZE;
    if (i == 0)
    {
        std::cout << "There are no contacts in the PhoneBook. Add some first!" << std::endl;
        return ;
    }
    print_list();
    std::cout << "Enter contact index to display(1 - " << i << "): ";
    std::string input;
    std::getline(std::cin, input);
    if(!is_num(input))
    {
        std::cout << "Index is not a number. Try a number!" << std::endl;
        return ;
    }
    the_index = std::stoi(input);
    if (the_index < 1 || the_index > i)
    {
        std::cout << "Index out of range. Try a number between 1 and " << i << std::endl; 
        return ;
    }
    print_details(the_index -1);
}