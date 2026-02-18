/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:12 by marvin            #+#    #+#             */
/*   Updated: 2026/02/17 13:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
        throw std::length_error("Span is already full");
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::length_error("Span too short");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}   

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::length_error("Span too short");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    return sorted.back() - sorted.front();
}

unsigned int Span::size() const
{
    return numbers.size();
}

std::vector<int> const &Span::getNumbers() const
{
    return numbers;
}

std::ostream &operator<<(std::ostream &os, const Span &span)
{
    os << "Span(" << span.size() << "/" << span.getNumbers().size() << "): {";
    std::vector<int> const &nums = span.getNumbers();

    for (size_t i = 0; i < nums.size(); ++i)
    {
        os << nums[i];
        if (i < nums.size() - 1)
            os << ", ";
    }
    os << "}";
    return os;
}