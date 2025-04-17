/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:40:14 by marvin            #+#    #+#             */
/*   Updated: 2025/04/16 14:40:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the Cat sound!
    j->makeSound(); //will output the Dog sound!
    meta->makeSound(); //will output the randomAnimal text!
    delete meta;
    delete j;
    delete i;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongCat* specificWrongCat = new WrongCat();
    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongMeta->makeSound(); // Outputs the WrongAnimal text!
    wrongCat->makeSound();  // Outputs the WrongAnimal text! (not the WrongCat sound)
    specificWrongCat->makeSound(); // Outputs the WrongCat sound
    delete wrongMeta;
    delete wrongCat;
    delete specificWrongCat;

    return (0);
}