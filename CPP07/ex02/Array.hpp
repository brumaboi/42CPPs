/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:00:11 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/20 12:00:11 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array {

    private:
        T* arr;
        unsigned int n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        ~Array();

        Array<T>& operator=(const Array<T>& other);
        T& operator[](unsigned int index);

        unsigned int size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"