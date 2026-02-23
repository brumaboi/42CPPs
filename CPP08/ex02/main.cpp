/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:36:32 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/21 18:36:32 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(void)
{
    std::cout << "\033[34m=== Subject test (MutantStack) ===\033[0m" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n\033[34m=== Same test with std::list (comparison) ===\033[0m" << std::endl;
    {
        std::list<int> mlist;

        mlist.push_back(5);
        mlist.push_back(17);

        std::cout << mlist.back() << std::endl;

        mlist.pop_back();

        std::cout << mlist.size() << std::endl;

        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        //[...]
        mlist.push_back(0);

        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << "\n\033[34m=== Testing const iterators ===\033[0m" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        const MutantStack<int> cmstack(mstack);
        std::cout << "Const iteration: ";
        for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Const top: " << cmstack.top() << std::endl;
        std::cout << "Const size: " << cmstack.size() << std::endl;
    }

    std::cout << "\n\033[34m=== Testing copy and assignment ===\033[0m" << std::endl;
    {
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> copy(original);
        MutantStack<int> assigned;
        assigned = original;

        copy.push(999);
        assigned.push(888);

        std::cout << "Original size: " << original.size() << std::endl;
        std::cout << "Copy size: " << copy.size() << std::endl;
        std::cout << "Assigned size: " << assigned.size() << std::endl;
    }

    return 0;
}