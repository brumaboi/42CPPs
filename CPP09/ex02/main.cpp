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
        checkInput(argc, argv);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::vector<int> vec;
    clock_t start_vec;
    clock_t end_vec;
    std::vector<int> copy_vec;
    fill_vec(copy_vec, argc, argv);
    std::cout << "Before: " << copy_vec << std::endl;
    start_vec = clock();
    fill_vec(vec, argc, argv);
    //sort logic here
    end_vec = clock();
    try {
        check_sorted_vec(vec);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }


    std::deque<int> deq;
    clock_t start_deq;
    clock_t end_deq;
    std::deque<int> copy_deq;
    fill_deq(copy_deq, argc, argv);
    start_deq = clock();
    fill_deq(deq, argc, argv);
    //sort logic here
    end_deq = clock();
    try {
        check_sorted_deq(deq);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "After: " << vec << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}