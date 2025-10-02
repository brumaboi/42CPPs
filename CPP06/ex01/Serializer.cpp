/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:15:46 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 16:15:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
    if (this != &other)
        *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    if (this != &other)
        *this = other;
    return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
    //to be implemented
}

Data* Serializer::deserialize(uintptr_t raw)
{
    //to be implemented
}