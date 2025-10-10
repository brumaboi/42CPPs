/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:49:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/10 22:43:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("Denis");
    FragTrap frag("Denis2");

    frag.attack("Albert");
    frag.takeDamage(3);
    frag.beRepaired(1);
    frag.highFivesGuys();
    frag.takeDamage(100);
    frag.highFivesGuys();
    return (0);
}