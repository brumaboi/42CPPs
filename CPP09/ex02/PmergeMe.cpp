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

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::checkInput(int argc, char **argv) {
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
        try {
            std::stoi(arg);
        } catch (const std::out_of_range &) {
            throw std::invalid_argument("Value out of int range: " + arg);
        }
    }
}

void PmergeMe::sortVector(std::vector<int> &c) {
    typedef std::pair<int, int> Pair;

    size_t n = c.size();
    if (n <= 1)
        return;

    bool hasUnpaired = (n % 2 != 0);
    int unpaired = 0;
    if (hasUnpaired)
        unpaired = c[n - 1];

    size_t pairCount = n / 2;
    std::vector<Pair> pairs;
    for (size_t i = 0; i < pairCount; ++i) {
        if (c[2 * i] >= c[2 * i + 1])
            pairs.push_back(std::make_pair(c[2 * i], c[2 * i + 1]));
        else
            pairs.push_back(std::make_pair(c[2 * i + 1], c[2 * i]));
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    PmergeMe::sortVector(winners);

    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<Pair> remainPairs = pairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        mainChain.push_back(winners[i]);
        for (size_t j = 0; j < remainPairs.size(); ++j) {
            if (remainPairs[j].first == winners[i]) {
                pend.push_back(remainPairs[j].second);
                remainPairs.erase(remainPairs.begin() + j);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    std::vector<size_t> order = jacobsthalOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    if (hasUnpaired) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }

    c = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &c) {
    typedef std::pair<int, int> Pair;

    size_t n = c.size();
    if (n <= 1)
        return;

    bool hasUnpaired = (n % 2 != 0);
    int unpaired = 0;
    if (hasUnpaired)
        unpaired = c[n - 1];

    size_t pairCount = n / 2;
    std::vector<Pair> pairs;
    for (size_t i = 0; i < pairCount; ++i) {
        if (c[2 * i] >= c[2 * i + 1])
            pairs.push_back(std::make_pair(c[2 * i], c[2 * i + 1]));
        else
            pairs.push_back(std::make_pair(c[2 * i + 1], c[2 * i]));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    PmergeMe::sortDeque(winners);

    std::deque<int> mainChain;
    std::deque<int> pend;
    std::vector<Pair> remainPairs = pairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        mainChain.push_back(winners[i]);
        for (size_t j = 0; j < remainPairs.size(); ++j) {
            if (remainPairs[j].first == winners[i]) {
                pend.push_back(remainPairs[j].second);
                remainPairs.erase(remainPairs.begin() + j);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    std::vector<size_t> order = jacobsthalOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    if (hasUnpaired) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }

    c = mainChain;
}

double PmergeMe::main_testVector(std::vector<int> &c, int argc, char **argv) {
    clock_t start = clock();
    PmergeMe::fill(c, argc, argv);
    PmergeMe::sortVector(c);
    clock_t end = clock();
    PmergeMe::checkSorted(c);
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

double PmergeMe::main_testDeque(std::deque<int> &c, int argc, char **argv) {
    clock_t start = clock();
    PmergeMe::fill(c, argc, argv);
    PmergeMe::sortDeque(c);
    clock_t end = clock();
    PmergeMe::checkSorted(c);
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t pendSize) {
    std::vector<size_t> order;
    if (pendSize <= 1)
        return order;
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < pendSize) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    for (size_t k = 3; k < jacob.size(); ++k) {
        size_t high = std::min(jacob[k], pendSize);
        size_t low = jacob[k - 1];
        for (size_t j = high; j > low; --j)
            order.push_back(j - 1);
    }
    return order;
}
