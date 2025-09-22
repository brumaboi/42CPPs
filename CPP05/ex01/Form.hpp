/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:27 by marvin            #+#    #+#             */
/*   Updated: 2025/09/22 23:03:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        Form();
        Form(const std::string &name, int signGrade, int executeGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        void beSigned(const Bureaucrat &bureaucrat);

        const std::string &getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class FormAlreadySignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const Form &form);
