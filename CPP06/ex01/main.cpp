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
    std::cout << "\033[34m=== Testing round-trip: deserialize(serialize(p)) == p ===\033[0m" << std::endl;
    {
        Data original{42, "hello"};
        uintptr_t raw = Serializer::serialize(&original);
        Data* restored = Serializer::deserialize(raw);

        std::cout << "&original: " << &original << std::endl;
        std::cout << "raw:       " << raw        << "  (" << std::hex << "0x" << raw << std::dec << ")" << std::endl;
        std::cout << "restored:  " << restored   << std::endl;
        std::cout << "match:     " << (restored == &original ? "OK" : "KO") << std::endl;
    }

    std::cout << "\n\033[34m=== Testing writing via restored affect original ===\033[0m" << std::endl;
    {
        Data original{10, "before"};
        Data* restored = Serializer::deserialize(Serializer::serialize(&original));

        std::cout << "before -> original: {" << original.value << ", " << original.str << "}" << std::endl;
        restored->value = 99;
        restored->str = "after";
        std::cout << "after  -> original: {" << original.value << ", " << original.str << "}" << std::endl;
        std::cout << "aliased:   " << (original.value == 99 && original.str == "after" ? "OK" : "KO") << std::endl;
    }

    return 0;
}