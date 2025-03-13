/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:55 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 11:48:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name(name),
      hitPoints(10),
      energyPoints(10),
      attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
    std::cout << "ClapTrap " << name << " is constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints < 0)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        return ;
    }
    if (energyPoints < 1)
    {
        std::cout << "ClapTrap " << name << " has no energy!" << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
