/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:23:16 by marvin            #+#    #+#             */
/*   Updated: 2025/01/23 15:23:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int HordeSize = 5;
    Zombie *horde = zombieHorde(HordeSize, "HordeZombie");
    int i = 0;
    while (i < HordeSize)
        horde[i++].announce();
    delete[] horde;
    return (0);
}