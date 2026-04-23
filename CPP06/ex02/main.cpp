/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:18:27 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 16:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
    std::cout << "\033[34m=== Testing generate() + identify(ptr) + identify(ref) ===\033[0m" << std::endl;
    {
        for (int i = 0; i < 10; i++)
        {
            Base* base = generate();
            std::cout << "\033[33m--- run " << i + 1 << " ---\033[0m" << std::endl;
            identify(base);
            identify(*base);
            delete base;
        }
    }
 
    return 0;
}