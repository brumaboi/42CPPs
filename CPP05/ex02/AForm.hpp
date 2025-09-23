/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:35 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 10:08:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        AForm();
        AForm(const std::string &name, int signGrade, int executeGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        void beSigned(const Bureaucrat &bureaucrat);

        const std::string &getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        virtual void execute(Bureaucrat const &executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);
