/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:18:21 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 16:18:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

class Base {

public:
    virtual ~Base() {}
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
