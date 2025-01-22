/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:59:38 by sbruma            #+#    #+#             */
/*   Updated: 2025/01/21 18:59:39 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {


private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;


public:
    Contact();
    ~Contact();

    void set_first_name(const std::string first_name);
    void set_last_name(const std::string last_name);
    void set_nickname(const std::string nickname);
    void set_phone_number(const std::string phone_number);
    void set_darkest_secret(const std::string darkest_secret);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;

    
};

#endif
