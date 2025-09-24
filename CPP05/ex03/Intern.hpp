/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:10:31 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 21:10:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class AForm;

class Intern {

    private:
        using FormCreator = AForm *(Intern::*)(const std::string &target) const;

        AForm *makePresidentialPardonForm(const std::string &target) const;
        AForm *makeRobotomyRequestForm(const std::string &target) const;
        AForm *makeShrubberyCreationForm(const std::string &target) const;

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;
};