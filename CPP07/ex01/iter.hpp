/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:28:51 by marvin            #+#    #+#             */
/*   Updated: 2025/10/06 23:28:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
    for (size_t i = 0; i < length; ++i)
    {
        function(array[i]);
    }
}