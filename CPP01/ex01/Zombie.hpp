/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:23:23 by marvin            #+#    #+#             */
/*   Updated: 2025/01/23 15:23:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie{

private:
    std::string name;

public:
    void announce(void);
    Zombie();
    Zombie(std::string name);
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif