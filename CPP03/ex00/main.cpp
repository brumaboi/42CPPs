/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:49:00 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 11:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Denis");
    
    clap.attack("Albert");
    clap.takeDamage(3);
    clap.beRepaired(1);
    clap.takeDamage(10);
    clap.attack("Bob"); //should print "is dead"
    return (0);
}