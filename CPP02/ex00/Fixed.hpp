/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:49:25 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/23 18:10:20 by sbruma           ###   ########.fr       */
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

    
};

#endif