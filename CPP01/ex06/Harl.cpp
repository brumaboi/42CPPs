/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:00:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 19:00:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    f[0] = &Harl::debug;
    f[1] = &Harl::info;
    f[2] = &Harl::warning;
    f[3] = &Harl::error;
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
    std::cout << std::endl;
    std::cout << "[DEBUG] " << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << std::endl;
    std::cout << "[INFO] " << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << std::endl;
    std::cout << "[WARNING] " << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << std::endl;
    std::cout << "[ERROR] " << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
            break ;
        i++;
    }
    switch (i)
    {
        case 0:
            (this->*f[0])();
            //fall through
        case 1:
            (this->*f[1])();
            //fall through
        case 2:
            (this->*f[2])();
            //fall through
        case 3:
            (this->*f[3])();
            break ;
    }
}
