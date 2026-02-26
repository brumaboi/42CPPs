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
    try{
        PmergeMe::checkInput(argc, argv);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::vector<int> vec;
    clock_t start_vec;
    clock_t end_vec;
    std::vector<int> copy_vec;
    PmergeMe::fill(copy_vec, argc, argv);
    std::cout << "\033[34mBefore: \033[0m" << copy_vec << std::endl;
    start_vec = clock();
    PmergeMe::fill(vec, argc, argv);
    PmergeMe::sort(vec);
    end_vec = clock();
    try {
        PmergeMe::checkSorted(vec);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::deque<int> deq;
    clock_t start_deq;
    clock_t end_deq;
    std::deque<int> copy_deq;
    PmergeMe::fill(copy_deq, argc, argv);
    start_deq = clock();
    PmergeMe::fill(deq, argc, argv);
    PmergeMe::sort(deq);
    end_deq = clock();
    try {
        PmergeMe::checkSorted(deq);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\033[34mAfter: \033[0m" << vec << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}