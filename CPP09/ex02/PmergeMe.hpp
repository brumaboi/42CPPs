/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:13:34 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/18 13:13:34 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <iomanip>
# include <string>
# include <stdexcept>
# include <exception>
# include <algorithm>
# include <utility>
# include <ctime>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static void checkInput(int argc, char **argv);
        static std::vector<size_t> jacobsthalOrder(size_t pendSize);

        template<typename Container>
        static void fill(Container &c, int argc, char **argv) {
            for (int i = 1; i < argc; ++i)
                c.push_back(std::stoi(argv[i]));
        }

        template<typename Container>
        static void checkSorted(const Container &c) {
            for (size_t i = 1; i < c.size(); ++i)
                if (c[i] < c[i - 1])
                    throw std::runtime_error("Container is not sorted");
        }

        static void sortVector(std::vector<int> &c);
        static void sortDeque(std::deque<int> &c);
        static double main_testVector(std::vector<int> &c, int argc, char **argv);
        static double main_testDeque(std::deque<int> &c, int argc, char **argv);
};

template<typename Container, typename = typename Container::value_type>
std::ostream &operator<<(std::ostream &os, const Container &c) {
    for (size_t i = 0; i < c.size(); ++i) {
        if (i > 0)
            os << " ";
        os << c[i];
    }
    return os;
}

#endif