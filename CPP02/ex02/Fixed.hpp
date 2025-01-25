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

#ifnder FIXED_HPP
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


};

std::ostream &operator<<(std::ostream &, const Fixed &fixed);

#endif