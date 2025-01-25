/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:40:13 by marvin            #+#    #+#             */
/*   Updated: 2025/01/25 12:40:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:
    int					_value;
    static const int	_fractionalBits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &src);

    Fixed &operator=(const Fixed &src);
    int		getRawBits(void) const;
    void	setRawBits(int const raw);

}
