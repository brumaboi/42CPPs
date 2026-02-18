/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:15 by marvin            #+#    #+#             */
/*   Updated: 2026/02/17 13:31:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span {

    private:
        std::vector<int> numbers;
        unsigned int maxSize;

    public:
        Span() = delete;
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span() = default;

        void addNumber(int number);
        template<typename InputIt>
        void addNumber(InputIt first, InputIt last)
        {
            if(std::distance(first, last) + numbers.size() > maxSize)
                throw std::length_error("Adding these numbers would exceed the maximum size of the Span.");
            numbers.insert(numbers.end(), first, last);
        }

        int shortestSpan() const;
        int longestSpan() const;

        unsigned int size() const;
        std::vector<int> const &getNumbers() const;
};

std::ostream &operator<<(std::ostream &os, const Span &span);
