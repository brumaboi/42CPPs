/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:45 by marvin            #+#    #+#             */
/*   Updated: 2025/09/27 22:59:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\033[34m=== Testing Intern Factory ===\033[0m" << std::endl;
    try {
        Intern intern;
        AForm* shrubForm = intern.makeForm("shrubbery creation", "home");
        AForm* robotForm = intern.makeForm("robotomy request", "Ianis");
        AForm* pardonForm = intern.makeForm("presidential pardon", "Stefan Bruma");
        
        AForm* unknownForm = intern.makeForm("unknown form", "target"); // Should throw exception
        (void)unknownForm; // To avoid unused variable warning

        if (shrubForm)
            std::cout << *shrubForm << std::endl;
        if (robotForm)
            std::cout << *robotForm << std::endl;
        if (pardonForm)
            std::cout << *pardonForm << std::endl;


        std::cout << "\n\033[34m=== Testing ShrubberyCreationForm via Intern ===\033[0m" << std::endl;
        try {
            Bureaucrat denis("Denis", 140);  // Can sign (145) but can't execute (137)
            Bureaucrat peter("Peter", 130);    // Can sign and execute
            if (shrubForm) {
                denis.signForm(*shrubForm);
                denis.executeForm(*shrubForm);  // Should fail - grade too low
                peter.executeForm(*shrubForm);   // Should succeed
            }
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }


        std::cout << "\n\033[34m=== Testing RobotomyRequestForm via Intern ===\033[0m" << std::endl;
        try {
            Bureaucrat robert("Robert", 60);  // Can sign (72) but can't execute (45)
            Bureaucrat albert("Albert", 40);  // Can sign and execute
            if (robotForm) {
                robert.signForm(*robotForm);
                robert.executeForm(*robotForm);    // Should fail - grade too low
                albert.executeForm(*robotForm);  // Should succeed (50% chance)

                for (int i = 0; i < 3; i++) {
                    AForm* newRobotForm = intern.makeForm("robotomy request", "MultiBender");
                    if (newRobotForm) {
                        robert.signForm(*newRobotForm);
                        albert.executeForm(*newRobotForm);
                        delete newRobotForm;
                    }
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }


        std::cout << "\n\033[34m=== Testing PresidentialPardonForm via Intern ===\033[0m" << std::endl;
        try {
            Bureaucrat david("David", 20);  // Can sign (25) but can't execute (5)
            Bureaucrat president("President", 1);  // Can sign and execute
            if (pardonForm) {
                david.signForm(*pardonForm);
                david.executeForm(*pardonForm);      // Should fail - grade too low
                president.executeForm(*pardonForm);  // Should succeed
            }
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n\033[34m=== Testing Form Exceptions via Intern-created Forms ===\033[0m" << std::endl;
        try {
            Bureaucrat boss("Boss", 1);

            AForm* testForm = intern.makeForm("shrubbery creation", "test");
            if (testForm) {
                boss.executeForm(*testForm);  // Should fail - form not signed
                boss.signForm(*testForm);
                boss.executeForm(*testForm);  // Should succeed
                delete testForm;
            }
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        delete shrubForm;
        delete robotForm;
        delete pardonForm;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}