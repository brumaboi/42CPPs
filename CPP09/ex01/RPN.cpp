/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:13:21 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/18 13:13:21 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>

int RPN::calculate(const std::string& input) {
    
    std::stack<double> stack;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token){
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for operator '" << token << "'" << std::endl;
                return 1;
            }

            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return 1;
                }
                stack.push(a / b);
            }
        } else {
            try {
                double num = std::stod(token);
                stack.push(num);
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
                return 1;
            }
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error: Invalid RPN expression" << std::endl;
        return 1;
    }
    else {
        std::cout << stack.top() << std::endl;
    }

    return 0;
}