/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:45 by marvin            #+#    #+#             */
/*   Updated: 2025/09/25 21:34:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Seed random number generator for RobotomyRequestForm
    std::srand(std::time(NULL));
    
    std::cout << "\033[34m=== Testing ShrubberyCreationForm ===\033[0m" << std::endl;
    try {
        Bureaucrat denis("Denis", 140);  // Can sign (145) but can't execute (137)
        Bureaucrat peter("Peter", 130);    // Can sign and execute
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        denis.signForm(shrub);
        denis.executeForm(shrub);  // Should fail - grade too low
        peter.executeForm(shrub);   // Should succeed
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[34m=== Testing RobotomyRequestForm ===\033[0m" << std::endl;
    try {
        Bureaucrat robert("Robert", 60);  // Can sign (72) but can't execute (45)
        Bureaucrat albert("Albert", 40);  // Can sign and execute
        RobotomyRequestForm robot("Ianis");
        std::cout << robot << std::endl;
        robert.signForm(robot);
        robert.executeForm(robot);    // Should fail - grade too low
        albert.executeForm(robot);  // Should succeed (50% chance)
        // Test randomness with multiple attempts
        for (int i = 0; i < 3; i++) {
            RobotomyRequestForm newRobot("MultiIanis");
            robert.signForm(newRobot);
            albert.executeForm(newRobot);
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[34m=== Testing PresidentialPardonForm ===\033[0m" << std::endl;
    try {
        Bureaucrat david("David", 20);  // Can sign (25) but can't execute (5)
        Bureaucrat president("President", 1);  // Can sign and execute
        PresidentialPardonForm pardon("Stefan Bruma");
        std::cout << pardon << std::endl;
        david.signForm(pardon);
        david.executeForm(pardon);      // Should fail - grade too low
        president.executeForm(pardon);  // Should succeed    
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n\033[34m=== Testing Form Exceptions ===\033[0m" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm form("test");
        // Test executing unsigned form
        boss.executeForm(form);  // Should fail - form not signed
        // Sign and execute successfully
        boss.signForm(form);
        boss.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}

