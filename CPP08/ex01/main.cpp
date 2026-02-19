/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:05 by marvin            #+#    #+#             */
/*   Updated: 2026/02/17 13:31:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::cout << "\033[34m=== Subject test ===\033[0m" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << sp << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing addNumber overflow ===\033[0m" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << "Span full: " << sp << std::endl;
        sp.addNumber(4);
        std::cout << "This should not print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing span with 0 or 1 element ===\033[0m" << std::endl;
    try {
        Span sp(1);
        std::cout << "Shortest span (empty): ";
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << "Longest span (1 elem): ";
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing range-based addNumber with vector ===\033[0m" << std::endl;
    try {
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);

        Span sp(10);
        sp.addNumber(vec.begin(), vec.end());
        std::cout << sp << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing range-based addNumber with list ===\033[0m" << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);

        Span sp(5);
        sp.addNumber(42);
        sp.addNumber(lst.begin(), lst.end());
        std::cout << sp << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing range-based addNumber overflow ===\033[0m" << std::endl;
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        Span sp(3);
        sp.addNumber(vec.begin(), vec.end());
        std::cout << "This should not print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing with 10000 elements ===\033[0m" << std::endl;
    try {
        Span sp(10000);
        std::srand(std::time(NULL));
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; i++)
            bigVec.push_back(std::rand());
        sp.addNumber(bigVec.begin(), bigVec.end());
        std::cout << "Size: " << sp.size() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing copy constructor and assignment ===\033[0m" << std::endl;
    try {
        Span sp1(5);
        sp1.addNumber(1);
        sp1.addNumber(10);
        sp1.addNumber(100);

        Span sp2(sp1);
        std::cout << "Original: " << sp1 << std::endl;
        std::cout << "Copy:     " << sp2 << std::endl;
        std::cout << "Copy shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Copy longest span: " << sp2.longestSpan() << std::endl;

        Span sp3(2);
        sp3.addNumber(42);
        sp3 = sp1;
        std::cout << "Assigned: " << sp3 << std::endl;
        std::cout << "Assigned shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Assigned longest span: " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing shortestSpan with duplicates ===\033[0m" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(1);
        sp.addNumber(3);
        sp.addNumber(3);
        sp.addNumber(100);
        sp.addNumber(200);
        std::cout << sp << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing with negative numbers ===\033[0m" << std::endl;
    try {
        Span sp(4);
        sp.addNumber(-100);
        sp.addNumber(0);
        sp.addNumber(50);
        sp.addNumber(100);
        std::cout << sp << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
