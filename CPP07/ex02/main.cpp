/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:00:05 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/20 12:00:05 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    std::cout << "\033[34m=== Testing empty array construction ===\033[0m" << std::endl;
    try {
        Array<int> empty;
        std::cout << "size = " << empty.size() << std::endl;
        empty[0]; // should throw (empty array, any index is out of bounds)
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing default initialization (new T[n]()) ===\033[0m" << std::endl;
    try {
        Array<int> a(5);
        std::cout << "size = " << a.size() << std::endl;
        std::cout << "values: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " "; // should all be 0
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing subscript operator with assignment ===\033[0m" << std::endl;
    try {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;
        std::cout << "values: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing out-of-bounds access ===\033[0m" << std::endl;
    try {
        Array<int> a(5);
        a[5]; // should throw (valid index: 0-4)
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing deep copy via copy constructor ===\033[0m" << std::endl;
    try {
        Array<int> original(3);
        for (unsigned int i = 0; i < original.size(); i++)
            original[i] = i + 1;
        Array<int> copy(original);
        copy[0] = 999; // modify copy, original must be untouched
        std::cout << "original: ";
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " "; // expect: 1 2 3
        std::cout << std::endl;
        std::cout << "copy:     ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " "; // expect: 999 2 3
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing deep copy via assignment operator ===\033[0m" << std::endl;
    try {
        Array<int> a(3);
        Array<int> b(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i + 1;
        b = a;
        a[0] = 42; // modify a, b must be untouched
        std::cout << "a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " "; // expect: 42 2 3
        std::cout << std::endl;
        std::cout << "b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " "; // expect: 1 2 3
        std::cout << std::endl;
        std::cout << "b.size() = " << b.size() << " (should be 3, not 5)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing-e self-assignment ===\033[0m" << std::endl;
    try {
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i + 1;
        Array<int>& ref = a;
        a = ref;
        std::cout << "values: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " "; // expect: 1 2 3
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    std::cout << "\n\033[34m=== Testing-e with std::string ===\033[0m" << std::endl;
    try {
        Array<std::string> s(3);
        s[0] = "hello";
        s[1] = "world";
        s[2] = "!";
        for (unsigned int i = 0; i < s.size(); i++)
            std::cout << s[i] << " ";
        std::cout << std::endl;
        Array<std::string> sc = s;
        sc[0] = "changed";
        std::cout << "original: " << s[0] << " (should still be hello)" << std::endl;
        std::cout << "copy:     " << sc[0] << " (should be changed)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: \033[31m" << e.what() << "\033[0m" << std::endl;
    }
 
    return 0;
}
