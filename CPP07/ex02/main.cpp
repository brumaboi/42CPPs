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

int main(void) {
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    try {
        a[5];
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

