/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:14:01 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 16:14:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    if (this != &other)
        *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
        *this = other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

////////////////////////////////////////////////////////////////////////////////////

static bool isSign(char c)
{
    return (c == '+' || c == '-');
}

std::string get_type(const std::string literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
        return "float";
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return "double";

    if (literal.size() == 1)
    {
        if (std::isdigit(static_cast<unsigned char>(literal[0])))
            return "int";
        return "char";
    }

    size_t i = 0;
    if (isSign(literal[0]))
        i = 1;
    if (i >= literal.size())
        return "invalid";

    bool trailingF = (literal.back() == 'f');
    if (trailingF)
    {
        std::string core = literal.substr(i, literal.size() - i - 1);
        auto dotPos = core.find('.');
        if (dotPos == std::string::npos)
            return "invalid";
        std::string intPart = core.substr(0, dotPos);
        std::string fracPart = core.substr(dotPos + 1);
        if (intPart.empty() || fracPart.empty())
            return "invalid";
        /// Check intPart and fracPart are digits with helpers
        return "float";
    }
    else
    {
        //no trailing f --> double or int
        std::string core = literal.substr(i);
        auto dotPos = core.find('.');
        if (dotPos == std::string::npos)
        {
            //int
            /// Check core is digits with helpers
            return "int";
        }
        else
        {
            std::string intPart = core.substr(0, dotPos);
            std::string fracPart = core.substr(dotPos + 1);
            if (intPart.empty() || fracPart.empty())
                return "invalid";
            /// Check intPart and fracPart are digits with helpers
            return "double";
        }
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    std::string type = get_type(literal);

    std::cout << type << std::endl;
}