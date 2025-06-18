/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:06:27 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 14:06:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        std::string name;
        bool isSigned;
        int signGrade;
        int executeGrade;

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
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif