/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:49:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 11:49:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap " << getName() << " is constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " is destructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else if (getHitPoints() <= 0)
        std::cout << "ScavTrap " << getName() << " is dead!" << std::endl;
    else
        std::cout << "ScavTrap " << getName() << " is out of energy!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (InGuard == true)
    {
        std::cout << "ScavTrap " << getName() << " is already in guard!" << std::endl;
    }
    else if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "ScavTrap " << getName() << " is now in guard!" << std::endl;
        InGuard = true;
    }
    else
        std::cout << "ScavTrap " << getName() << " is already dead!" << std::endl;
}
