/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:15:42 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 16:15:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data a{1, "a"}, b{2, "b"};

    // Serialize the pointer to Data
    uintptr_t SerializedData = Serializer::serialize(&a);
    std::cout << "Serialized value: " << SerializedData << std::endl;
    // Deserialize the uintptr_t back to a pointer to Data
    Data* deserializedData = Serializer::deserialize(SerializedData);
    std::cout << "Deserialized value: " << deserializedData->value << std::endl;

    // Check if the original and deserialized pointers are the same
    if (deserializedData == &a)
        std::cout << "Success: The original and deserialized pointers are the same." << std::endl;
    else
        std::cout << "Error: The pointers do not match!" << std::endl;

    // Check with incorrect data
    if (deserializedData == &b)
        std::cout << "Success: The original and deserialized pointers are the same." << std::endl;
    else
        std::cout << "Error: The pointers do not match!" << std::endl;
    return 0;
}