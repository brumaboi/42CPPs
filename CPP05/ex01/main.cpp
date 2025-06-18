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
#include "Form.hpp"

int main()
{
    std::cout << "Test 1: " << std::endl;
    try
    {
        Form form("Form1", 50, 30);
        Bureaucrat bureaucrat("Bureaucrat1", 20);
        std::cout << form << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 2: " << std::endl;
    try
    {
        Form form("Form2", 20, 10);
        Bureaucrat bureaucrat("Bureaucrat2", 50);
        std::cout << form << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 3:" << std::endl;
    try
    {
        Form form("Form3", 0, 10);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}