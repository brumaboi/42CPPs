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
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <exception>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec);
std::ostream &operator<<(std::ostream &os, const std::deque<int> &deq);

void checkInput(int argc, char **argv);
void fill_vec(std::vector<int> &vec, int argc, char **argv);
void fill_deq(std::deque<int> &deq, int argc, char **argv);
void check_sorted_vec(const std::vector<int> &vec);
void check_sorted_deq(const std::deque<int> &deq);

#endif
