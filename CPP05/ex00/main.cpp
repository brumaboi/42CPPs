/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:55:19 by marvin            #+#    #+#             */
/*   Updated: 2025/09/25 23:39:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[34m=== Testing Increment/Decrement around upper bound ===\033[0m" << std::endl;
    try {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();  // Should throw (grade would go above highest)
        std::cout << bureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing Decrement at lower bound ===\033[0m" << std::endl;
    try {
        Bureaucrat bureaucrat("Bureaucrat", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();  // Should throw (grade would go below lowest)
        std::cout << bureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing Construct with too-high grade (0) ===\033[0m" << std::endl;
    try {
        Bureaucrat bureaucrat("Bureaucrat", 0);  // Should throw
        (void)bureaucrat;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing Construct with too-low grade (151) ===\033[0m" << std::endl;
    try {
        Bureaucrat bureaucrat("Bureaucrat", 151);  // Should throw
        (void)bureaucrat;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}