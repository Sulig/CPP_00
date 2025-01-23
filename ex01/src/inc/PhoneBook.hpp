/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:40:23 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/23 18:01:19 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		atoi(std::string str);
		int		lastContact(PhoneBook phoneBook);
		std::string	trim(std::string str);
		std::string	manageInput(void);
		void		showContacts(PhoneBook phoneBook);
		PhoneBook	addContact(PhoneBook phoneBook);
	private:
		Contact	contacts[8];
};

#endif
