/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:28:53 by marvin            #+#    #+#             */
/*   Updated: 2025/10/06 23:28:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int intArr[] = {1, 2, 3, 4, 5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    std::string strArr[] = {"one", "two", "three", "four", "five"};

    iter(intArr, 5, [](int &n) { std::cout << n << std::endl; });
    iter(charArr, 5, [](char &c) { std::cout << c << std::endl; });
    iter(strArr, 5, [](std::string &s) { std::cout << s << std::endl; });

    return 0;
}