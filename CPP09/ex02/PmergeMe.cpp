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

// Static methods
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
        std::stoi(arg);
    }
}

void PmergeMe::fill(std::vector<int> &vec, int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        vec.push_back(std::stoi(argv[i]));
    }
}

void PmergeMe::fill(std::deque<int> &deq, int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        deq.push_back(std::stoi(argv[i]));
    }
}

void PmergeMe::checkSorted(const std::vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            throw std::runtime_error("Vector is not sorted");
        }
    }
}

void PmergeMe::checkSorted(const std::deque<int> &deq) {
    for (size_t i = 1; i < deq.size(); ++i) {
        if (deq[i] < deq[i - 1]) {
            throw std::runtime_error("Deque is not sorted");
        }
    }
}

static std::vector<size_t> getJacobsthalOrder(size_t pendSize) {
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

void PmergeMe::sort(std::vector<int> &vec) {
    size_t n = vec.size();
    if (n <= 1)
        return;

    bool hasUnpaired = (n % 2 != 0);
    int unpaired = 0;
    if (hasUnpaired)
        unpaired = vec[n - 1];

    size_t pairCount = n / 2;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < pairCount; ++i) {
        if (vec[2 * i] >= vec[2 * i + 1])
            pairs.push_back(std::make_pair(vec[2 * i], vec[2 * i + 1]));
        else
            pairs.push_back(std::make_pair(vec[2 * i + 1], vec[2 * i]));
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    sort(winners);

    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<std::pair<int, int> > remainPairs = pairs;
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

    std::vector<size_t> order = getJacobsthalOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    if (hasUnpaired) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }

    vec = mainChain;
}

void PmergeMe::sort(std::deque<int> &deq) {
    size_t n = deq.size();
    if (n <= 1)
        return;

    bool hasUnpaired = (n % 2 != 0);
    int unpaired = 0;
    if (hasUnpaired)
        unpaired = deq[n - 1];

    size_t pairCount = n / 2;
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < pairCount; ++i) {
        if (deq[2 * i] >= deq[2 * i + 1])
            pairs.push_back(std::make_pair(deq[2 * i], deq[2 * i + 1]));
        else
            pairs.push_back(std::make_pair(deq[2 * i + 1], deq[2 * i]));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    sort(winners);

    std::deque<int> mainChain;
    std::deque<int> pend;
    std::deque<std::pair<int, int> > remainPairs = pairs;
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

    mainChain.push_front(pend[0]);

    std::vector<size_t> order = getJacobsthalOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    if (hasUnpaired) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }

    deq = mainChain;
}

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
