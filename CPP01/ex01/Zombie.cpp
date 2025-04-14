/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:23:20 by marvin            #+#    #+#             */
/*   Updated: 2025/01/23 15:23:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): name("Zombie")
{   
}

Zombie::Zombie(std::string name): name(name)
{
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void Zombie::setName(std::string name)
{
    this->name = name;
}
