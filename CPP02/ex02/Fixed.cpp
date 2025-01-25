/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:17:07 by marvin            #+#    #+#             */
/*   Updated: 2025/01/25 13:17:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
    :_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
    :_value(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    :_value(roundf(value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = src.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// //6 comparison operators
//     bool  operator>(const Fixed &fixed) const;
//     bool  operator<(const Fixed &fixed) const;
//     bool  operator>=(const Fixed &fixed) const;
//     bool  operator<=(const Fixed &fixed) const;
//     bool  operator==(const Fixed &fixed) const;
//     bool  operator!=(const Fixed &fixed) const;

// //4 arithmetic operators
//     Fixed operator+(const Fixed &fixed) const;
//     Fixed operator-(const Fixed &fixed) const;
//     Fixed operator*(const Fixed &fixed) const;
//     Fixed operator/(const Fixed &fixed) const;

// //4 increment/decrement operators
//     Fixed &operator++();
//     Fixed operator++(int);
//     Fixed &operator--();
//     Fixed operator--(int);

// //overload member functions
//     static Fixed &min(Fixed &a, Fixed &b);
//     static const Fixed &min(const Fixed &a, const Fixed &b);
//     static Fixed &max(Fixed &a, Fixed &b);
//     static const Fixed &max(const Fixed &a, const Fixed &b);