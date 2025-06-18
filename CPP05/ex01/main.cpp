/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:55:19 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 13:55:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Test 1: " << std::endl;
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade(); // This should throw an exception
        std::cout << bureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 2: " << std::endl;
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade(); // This should throw an exception
        std::cout << bureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 3: " << std::endl;
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 0); // This should throw an exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 4: " << std::endl;
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 151); // This should throw an exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }    
}