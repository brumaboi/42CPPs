/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:28:12 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/21 18:39:10 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int     i;
    int     j;

    if (argc == 1)
    {
        std::cout << "*  LOUD AND UNBEARABLE FEEDBACK NOISE  *";
        return(0);
    }
    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] <= 'z' && argv[i][j] >= 'a')
                argv[i][j] = std::toupper(argv[i][j]);
            std::cout << argv[i][j];
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}
