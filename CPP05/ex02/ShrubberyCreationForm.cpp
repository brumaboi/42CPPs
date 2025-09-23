/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:08:40 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 10:09:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("Could not open file for writing");
    outfile << "       $" << std::endl;
    outfile << "      ###" << std::endl;
    outfile << "     #####" << std::endl;
    outfile << "    #######" << std::endl;
    outfile << "   #########" << std::endl;
    outfile << "  ###########" << std::endl;
    outfile << "       ||" << std::endl;
    outfile << "       ||" << std::endl;
    outfile << std::endl;
}