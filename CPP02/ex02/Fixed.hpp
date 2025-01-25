/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:17:04 by marvin            #+#    #+#             */
/*   Updated: 2025/01/25 13:17:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{


private:
    int                 _value;
    static const int    _fractionalBits = 8;


public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &src);
    ~Fixed();

    Fixed &operator=(const Fixed &src);
    int		getRawBits(void) const;
    void	setRawBits(int const raw);
    int		toInt(void) const;
    float	toFloat(void) const;

//6 comparison operators
    bool  operator>(const Fixed &fixed) const;
    bool  operator<(const Fixed &fixed) const;
    bool  operator>=(const Fixed &fixed) const;
    bool  operator<=(const Fixed &fixed) const;
    bool  operator==(const Fixed &fixed) const;
    bool  operator!=(const Fixed &fixed) const;

//4 arithmetic operators
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

//4 increment/decrement operators
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

//overload member functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &, const Fixed &fixed);

#endif