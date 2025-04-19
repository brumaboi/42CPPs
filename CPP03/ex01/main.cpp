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

#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Denis");
    ScavTrap scav("Denis2");
    
    scav.attack("Albert");
    scav.takeDamage(3);
    scav.beRepaired(1);
    scav.guardGate();
    scav.guardGate();
    clap.attack("Albert");
    clap.takeDamage(3);
    clap.beRepaired(1);
    return (0);
}