/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:36:35 by sadoming          #+#    #+#             */
/*   Updated: 2024/09/17 17:36:35 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret;) 
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone = phone;
    this->secret = secret;
}