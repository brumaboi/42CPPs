/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:31:00 by marvin            #+#    #+#             */
/*   Updated: 2026/02/17 13:31:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    std::cout << "\033[34m=== Testing easyfind with std::vector ===\033[0m" << std::endl;
    try {
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(i * 3);
        // Search for existing values
        std::vector<int>::iterator it = easyfind(vec, 9);
        std::cout << "Found value: " << *it << std::endl;
        it = easyfind(vec, 0);
        std::cout << "Found value: " << *it << std::endl;
        it = easyfind(vec, 27);
        std::cout << "Found value: " << *it << std::endl;
        // Search for non-existing value
        it = easyfind(vec, 42);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing easyfind with std::list ===\033[0m" << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(7);
        lst.push_back(42);
        lst.push_back(-5);
        lst.push_back(100);
        // Search for existing values
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Found value: " << *it << std::endl;
        it = easyfind(lst, -5);
        std::cout << "Found value: " << *it << std::endl;
        // Search for non-existing value
        it = easyfind(lst, 2);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing easyfind with std::deque ===\033[0m" << std::endl;
    try {
        std::deque<int> deq;
        deq.push_back(10);
        deq.push_back(20);
        deq.push_back(30);
        deq.push_front(5);
        // Search for existing value
        std::deque<int>::iterator it = easyfind(deq, 5);
        std::cout << "Found value: " << *it << std::endl;
        it = easyfind(deq, 30);
        std::cout << "Found value: " << *it << std::endl;
        // Search for non-existing value
        it = easyfind(deq, 99);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing easyfind with empty container ===\033[0m" << std::endl;
    try {
        std::vector<int> empty;
        std::vector<int>::iterator it = easyfind(empty, 0);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
