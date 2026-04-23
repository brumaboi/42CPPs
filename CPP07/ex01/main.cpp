/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:28:53 by marvin            #+#    #+#             */
/*   Updated: 2025/10/06 23:28:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::cout << "\033[34m=== Testing iter with int array (non-const ref, mutation) ===\033[0m" << std::endl;
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::cout << "before: ";
        iter(arr, 5, [](int& n) { std::cout << n << " "; });
        std::cout << std::endl;
        iter(arr, 5, [](int& n) { n *= 2; }); // mutate in place
        std::cout << "after (*2): ";
        iter(arr, 5, [](int& n) { std::cout << n << " "; }); // expect: 2 4 6 8 10
        std::cout << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing iter with char array ===\033[0m" << std::endl;
    {
        char arr[] = {'a', 'b', 'c', 'd', 'e'};
        iter(arr, 5, [](char& c) { std::cout << c << " "; }); // expect: a b c d e
        std::cout << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing iter with std::string array ===\033[0m" << std::endl;
    {
        std::string arr[] = {"one", "two", "three", "four", "five"};
        iter(arr, 5, [](std::string& s) { std::cout << s << " "; });
        std::cout << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing iter with const array (const ref required) ===\033[0m" << std::endl;
    {
        const int arr[] = {10, 20, 30, 40, 50};
        iter(arr, 5, [](const int& n) { std::cout << n << " "; }); // expect: 10 20 30 40 50
        std::cout << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing iter with double array ===\033[0m" << std::endl;
    {
        double arr[] = {1.1, 2.2, 3.3};
        iter(arr, 3, [](double& d) { std::cout << d << " "; }); // expect: 1.1 2.2 3.3
        std::cout << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing iter with regular function (not lambda) ===\033[0m" << std::endl;
    {
        struct Printer {
            static void print(int& n) { std::cout << "[" << n << "] "; }
        };
        int arr[] = {7, 8, 9};
        iter(arr, 3, Printer::print); // expect: [7] [8] [9]
        std::cout << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing-e iter with empty array (length = 0) ===\033[0m" << std::endl;
    {
        int arr[] = {1, 2, 3};
        std::cout << "calling iter with length 0 (should print nothing): ";
        iter(arr, 0, [](int& n) { std::cout << n << " "; });
        std::cout << "(done)" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing-e iter with single-element array ===\033[0m" << std::endl;
    {
        int arr[] = {42};
        iter(arr, 1, [](int& n) { std::cout << n; }); // expect: 42
        std::cout << std::endl;
    }
 
    return 0;
}
