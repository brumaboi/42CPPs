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

void general_out(std::string c, std::string i, std::string f, std::string d)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

std::string cfloat(float f)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << f << "f";
    return oss.str();
}

std::string cdouble(double d)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << d;
    return oss.str();
}

void convert_out(std::string type, std::string literal)
{
    if (type == "char")
    {
        int i = static_cast<int>(literal[0]);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);
        general_out(literal, std::to_string(i), cfloat(f), cdouble(d));
    }
    
    if (type == "int")
    {
        int i = std::stoi(literal);
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);
        general_out(std::string(1, c), std::to_string(i), cfloat(f), cdouble(d));
    }

    if (type == "float")
    {
        float f = std::stof(literal);
        int i = static_cast<int>(f);
        char c = static_cast<char>(i);
        double d = static_cast<double>(f);
        general_out(std::string(1, c), std::to_string(i), cfloat(f), cdouble(d));
    }

    if (type == "double")
    {
        double d = std::stod(literal);
        int i = static_cast<int>(d);
        char c = static_cast<char>(i);
        float f = static_cast<float>(d);
        general_out(std::string(1, c), std::to_string(i), cfloat(f), cdouble(d));
    }

    if (type == "invalid")
    {
        std::cout << "Invalid literal" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    std::string type = get_type(literal);

    convert_out(type, literal);
}