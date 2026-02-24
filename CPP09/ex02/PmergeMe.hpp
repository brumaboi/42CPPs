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

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <exception>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    static void checkInput(int argc, char **argv);
    static void fill(std::vector<int> &vec, int argc, char **argv);
    static void fill(std::deque<int> &deq, int argc, char **argv);
    static void checkSorted(const std::vector<int> &vec);
    static void checkSorted(const std::deque<int> &deq);
    static void sort(std::vector<int> &vec);
    static void sort(std::deque<int> &deq);


};

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec);
std::ostream &operator<<(std::ostream &os, const std::deque<int> &deq);
