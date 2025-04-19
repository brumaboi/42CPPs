/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:58 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 11:48:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
        std::string     name;
        int    hitPoints;
        int    energyPoints;
        int    attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &src);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setHitPoints(int hitPoints);
        int getHitPoints() const;
        void setEnergyPoints(int energyPoints);
        int getEnergyPoints() const;
        void setAttackDamage(int attackDamage);
        int getAttackDamage() const;
        std::string getName() const;
};

#endif