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

Contact::get_first_name() const
{
    return _first_name;
}

Contact::get_last_name() const
{
    return _last_name;
}

Contact::get_nickname() const
{
    return _nickname;
}

Contact::get_phone_number() const
{
    return _phone_number;
}

Contact::get_darkest_secret() const
{
    return _darkest_secret;
}

