/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:13:26 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/18 13:13:26 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        PmergeMe::checkInput(argc, argv);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::vector<int> copy_vec;
    PmergeMe::fill(copy_vec, argc, argv);
    std::cout << "\033[34mBefore: \033[0m" << copy_vec << std::endl;

    std::vector<int> vec;
    std::deque<int> deq;
    double elapsed_vec, elapsed_deq;
    try {
        elapsed_vec = PmergeMe::main_testVector(vec, argc, argv);
        elapsed_deq = PmergeMe::main_testDeque(deq, argc, argv);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\033[34mAfter(vec): \033[0m" << vec << std::endl;
    std::cout << "\033[34mAfter(deq): \033[0m" << deq << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << elapsed_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << elapsed_deq << " us" << std::endl;

    return 0;
}