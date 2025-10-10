/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:50:52 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 11:50:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " is constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap " << getName() << " is constructed!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " is destructed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else if (getHitPoints() <= 0)
        std::cout << "FragTrap " << getName() << " is dead!" << std::endl;
    else
        std::cout << "FragTrap " << getName() << " is out of energy!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (getHitPoints() <= 0)
    {
        std::cout << "FragTrap " << getName() << " can not high five while dead!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << getName() << " is requesting a high five!" << std::endl;
}