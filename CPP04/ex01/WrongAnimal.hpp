/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:58:36 by marvin            #+#    #+#             */
/*   Updated: 2025/04/16 15:58:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    
        protected:
            std::string type;
    
        public:
            WrongAnimal();
            WrongAnimal(const WrongAnimal &other);
            WrongAnimal &operator=(const WrongAnimal &other);
            virtual ~WrongAnimal();
    
            void makeSound() const;
            std::string getType() const;
};

#endif