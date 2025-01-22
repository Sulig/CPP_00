/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:40:45 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/22 18:05:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class Contact
{
	public:
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, int phone,
		std::string secret);
		~Contact();
		int		Contact::isNull(Contact contact);
		void	Contact::displayInSearch(Contact contact, int index);
		void	Contact::displayAll(Contact contact);
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		int			phone;
		std::string	secret;
		void	Contact::displayLargeStrings(std::string toPrint);
};

#endif
