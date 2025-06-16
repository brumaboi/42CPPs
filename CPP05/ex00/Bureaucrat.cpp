/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:55:10 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 13:55:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (stream);
}