/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:14:39 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 21:14:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this == &other)
        return *this;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) const 
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) const 
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    static const FormCreator formCreators[3] = {
        &Intern::makePresidentialPardonForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " because it is unknown." << std::endl;
    return nullptr;
}
