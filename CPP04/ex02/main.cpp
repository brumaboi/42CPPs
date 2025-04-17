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

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the Cat sound!
    j->makeSound(); //will output the Dog sound!
    // meta->makeSound(); //will output the randomAnimal text!
    // delete meta;
    delete j;
    delete i;

    const int N = 4;
    Animal* animals[N];
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < N; i++)
        delete animals[i];

    Dog originalDOG;
    originalDOG.getBrain()->ideas[0] = "I am a dog!";
    Dog copyDOG(originalDOG);
    Dog assignedDOG;
    assignedDOG = originalDOG;
    copyDOG.getBrain()->ideas[0] = "I am a copy of a dog!";
    std::cout << "Original Dog Brain Idea: " << originalDOG.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy Dog Brain Idea: " << copyDOG.getBrain()->ideas[0] << std::endl;
    std::cout << "Assigned Dog Brain Idea: " << assignedDOG.getBrain()->ideas[0] << std::endl;
    return (0);
}