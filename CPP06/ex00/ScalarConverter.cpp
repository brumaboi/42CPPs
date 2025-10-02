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

//=========SPECIAL MEMBERS=========//
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

//====================HELPERS====================//
static bool isSign(char c)
{
    return (c == '+' || c == '-');
}

static bool isUnsignedDigit(std::string const& str)
{
    if (str.empty())
        return false;
    for (unsigned char c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

//====================TYPE DETECTION====================//
std::string get_type(const std::string literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
        return "float";
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
        return "double";

    if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return "char";

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
        if ((!isUnsignedDigit(intPart) && !intPart.empty())
            || (!isUnsignedDigit(fracPart) && !fracPart.empty()))
            return "invalid";
        return "float";
    }
    else
    {
        //no trailing f --> double or int
        std::string core = literal.substr(i);
        auto dotPos = core.find('.');
        if (dotPos == std::string::npos)
        {
            if (!isUnsignedDigit(core))
                return "invalid";
            return "int";
        }
        else
        {
            std::string intPart = core.substr(0, dotPos);
            std::string fracPart = core.substr(dotPos + 1);
            if (intPart.empty() || fracPart.empty())
                return "invalid";
            if ((!isUnsignedDigit(intPart) && !intPart.empty())
                || (!isUnsignedDigit(fracPart) && !fracPart.empty()))
                return "invalid";
            return "double";
        }
    }
}


//====================OUTPUT====================//
void general_out(std::string c, std::string i, std::string f, std::string d)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

static std::string outChar(double c)
{
    if (!std::isfinite(c) || c < 0 || c > 127)
        return "impossible";
    
    int v = static_cast<int>(c);
    unsigned char uc = static_cast<unsigned char>(v);
    if (!std::isprint(uc))
        return "Non displayable";
    return std::string(1, static_cast<char>(uc));
}

static std::string outInt(double i)
{
    if (!std::isfinite(i))
        return "impossible";
    if (i < static_cast<double>(std::numeric_limits<int>::min()) || i > static_cast<double>(std::numeric_limits<int>::max()))
        return "impossible";
    return std::to_string(static_cast<int>(i));
}

static std::string outFloat(float f)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << f << "f";
    return oss.str();
}

static std::string outDouble(double d)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << d;
    return oss.str();
}

//====================CONVERSION====================//
void convert_out(std::string type, std::string literal)
{
    try
    {
        double l;
        if (type == "char")
        {
            char c = (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') ? literal[1] : literal[0];
            l = static_cast<unsigned char>(c);
        }
        
        else if (type == "int")
        {
            long long ll = std::stold(literal);
            l = static_cast<double>(ll);
        }

        else if (type == "float")
        {
            l = static_cast<double>(std::stof(literal));
        }

        else if (type == "double")
        {
            l = std::stod(literal);
        }
        else
        {
            throw std::exception();
        }

        general_out(outChar(l), outInt(l), outFloat(l), outDouble(l));
            
    } catch (const std::exception&){
        std::cout << "Invalid literal" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    std::string type = get_type(literal);

    convert_out(type, literal);
}
