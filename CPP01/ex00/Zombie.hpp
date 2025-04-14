/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2025/01/23 15:22:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{

private:
    std::string name;

public:
    void announce(void);
    void setName(std::string name);
    Zombie(std::string name);
    ~Zombie();

Zombie* newZombie( std::string name );
void randomChump( std::string name );
};

#endif