/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:59:40 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/21 18:59:42 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_first_name(const std::string first_name) ///need to check for alphabetical
{
    _first_name = first_name;
}

Contact::get_first_name() const
{
    return _first_name;
}

void Contact::set_last_name(const std::string last_name) ///need to check for alphabetical
{
    _last_name = last_name;
}

Contact::get_last_name() const
{
    return _last_name;
}

void Contact::set_nickname(const std::string nickname) ///need to check for alphabetical
{
    _nickname = nickname;
}

Contact::get_nickname() const
{
    return _nickname;
}

void Contact::set_phone_number(const std::string phone_number) ///need to check for numerical
{
    _phone_number = phone_number;
}

Contact::get_phone_number() const
{
    return _phone_number;
}

void Contact::set_darkest_secret(const std::string darkest_secret)
{
    _darkest_secret = darkest_secret;
}

Contact::get_darkest_secret() const
{
    return _darkest_secret;
}

