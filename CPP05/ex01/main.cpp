/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:55:19 by marvin            #+#    #+#             */
/*   Updated: 2025/09/26 00:18:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\033[34m=== Testing Successful signing ===\033[0m" << std::endl;
    try {
        Form       form("Form1", 50, 30);
        Bureaucrat bureaucrat("Bureaucrat1", 20);
        std::cout << form << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[34m=== Testing Signing fails (grade too low) ===\033[0m" << std::endl;
    try {
        Form       form("Form2", 20, 10);
        Bureaucrat bureaucrat("Bureaucrat2", 50);
        std::cout << form << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\n\033[34m=== Testing Invalid form construction (out of bounds) ===\033[0m" << std::endl;
    try {
        Form form("Form3", 0, 10); // should throw
        std::cout << form << std::endl; // not reached
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}