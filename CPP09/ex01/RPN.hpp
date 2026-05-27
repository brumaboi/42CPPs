/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:13:24 by sbruma            #+#    #+#             */
/*   Updated: 2026/05/27 14:43:58 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <cctype>

class RPN {

    private:
        RPN() = delete;
        RPN(const RPN& other) = delete;
        RPN& operator=(const RPN& other) = delete;
        ~RPN() = delete;  

    public:
        static int calculate(const std::string& input);
};

#endif