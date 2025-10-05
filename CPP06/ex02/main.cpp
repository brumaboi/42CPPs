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
    for (int i = 0; i < 10; i++)
    {
        Base *base = generate();
        identify(base); // identify using pointer
        identify(*base); // identify using reference
        delete base;
        std::cout << "---------------------" << std::endl;
    }
    return 0;
}