/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:13:32 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/18 13:13:32 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0)
            os << " ";
        os << vec[i];
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::deque<int> &deq) {
    for (size_t i = 0; i < deq.size(); ++i) {
        if (i > 0)
            os << " ";
        os << deq[i];
    }
    return os;
}

void checkInput(int argc, char **argv) {
    if (argc < 2) {
        throw std::invalid_argument("Usage: " + std::string(argv[0]) + " <numbers...>");
    }
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!std::isdigit(arg[j])) {
                throw std::invalid_argument("Invalid input: " + arg);
            }
        }
        std::stoi(arg);
    }
}

void fill_vec(std::vector<int> &vec, int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        vec.push_back(std::stoi(argv[i]));
    }
}

void fill_deq(std::deque<int> &deq, int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        deq.push_back(std::stoi(argv[i]));
    }
}

void check_sorted_vec(const std::vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            throw std::runtime_error("Vector is not sorted");
        }
    }
}

void check_sorted_deq(const std::deque<int> &deq) {
    for (size_t i = 1; i < deq.size(); ++i) {
        if (deq[i] < deq[i - 1]) {
            throw std::runtime_error("Deque is not sorted");
        }
    }
}
