/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:55:10 by marvin            #+#    #+#             */
/*   Updated: 2025/09/26 00:18:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        setGrade(other.grade);
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    setGrade(grade - 1);
}

void Bureaucrat::decrementGrade()
{
    setGrade(grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.';
    return (stream);
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name << " cannot sign " << form.getName() << " because: \033[31m" << e.what() << " \033[0m" << std::endl;
    }
}
