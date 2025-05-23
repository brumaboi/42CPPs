/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:57:15 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 17:57:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int copy_replace(const std::string &sourceFile, const std::string &s1, const std::string &s2)
{   
    std::ifstream inputFile(sourceFile);
    if (!inputFile.is_open())
        return(std::cerr << "Error: Can not open file." << sourceFile << std::endl, 1);
    std::ofstream outputFile(sourceFile + ".replace");
    if (!outputFile.is_open())
    {
        inputFile.close();
        return (std::cerr << "Error: Can not open file." << sourceFile + ".replace" << std::endl, 1);
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string result;
        size_t pos = 0;
        while (pos < line.length())
        {
            if (line.substr(pos, s1.length()) == s1)
            {
                result += s2;
                pos += s1.length();
            }
            else
            {
                result += line[pos];
                pos++;
            }
        }
        outputFile << result;
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return (0);
}

int check_input(int argc, char **argv)
{
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (argc != 4)
        return (std::cout<< "Error: Wrong number of arguments."<<std::endl, 1);
    if (s1.empty() || s2.empty())
        return (std::cout<< "Error: Empty string."<<std::endl, 1);
    if (s1 == s2)
        return (std::cout<< "Error: Same string."<<std::endl, 1);
    std::fstream file(argv[1], std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Can't access file: " << argv[1] << std::endl;
		return (1);
	}
	file.close();
    return (0);
}

int main(int argc, char **argv)
{
    if (check_input(argc, argv) == 1)
        return (1);
    if (copy_replace(argv[1], argv[2], argv[3]) == 1)
        return (1);
    return (0);
}
