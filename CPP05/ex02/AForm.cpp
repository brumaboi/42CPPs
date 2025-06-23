/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:32 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 14:06:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form() : name("default form"), isSigned(false), signGrade(150), executeGrade(150)
{
}

Form::Form(const std::string &name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
    if (this == &other)
        return (*this);
    this->isSigned = other.isSigned;
    return (*this);
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const std::string &Form::getName() const
{
    return (name);
}

bool Form::getSigned() const
{
    return (isSigned);
}

int Form::getSignGrade() const
{
    return (signGrade);
}

int Form::getExecuteGrade() const
{
    return (executeGrade);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
    stream << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return (stream);
}
