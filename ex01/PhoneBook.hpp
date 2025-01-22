/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:59:43 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/21 18:59:44 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

# ifndef MAX_SIZE
#  define MAX_SIZE 8
# endif

class PhoneBook {


private:
    Contact _contacts[MAX_SIZE];
    size_t  _index;
    void    print_list() const;
    void    print_details(size_t index) const;


public:
    PhoneBook();
    ~PhoneBook();
    
    void    add_contact();
    void    search_contact();


};

#endif