/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:32 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 10:48:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default form"), isSigned(false), signGrade(150), executeGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this == &other)
        return (*this);
    this->isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    if (isSigned == true)
        throw FormAlreadySignedException();
    else
        isSigned = true;
}

const std::string &AForm::getName() const
{
    return (name);
}

bool AForm::getSigned() const
{
    return (isSigned);
}

int AForm::getSignGrade() const
{
    return (signGrade);
}

int AForm::getExecuteGrade() const
{
    return (executeGrade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
    stream << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return (stream);
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (isSigned == false)
        throw FormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
}
