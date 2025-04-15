/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:00:33 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 19:00:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl{

    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harl(void);
        ~Harl(void);
        void complain( std::string level );
};

#endif