/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:40:45 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/24 16:32:14 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, int phone,
		std::string secret);
		~Contact(void);
		int	isNull(Contact contact);
		void	displayLargeStrings(std::string toPrint);
		void	displayInSearch(Contact contact, int index);
		void	displayAll(Contact contact);
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		int			phone;
		std::string	secret;
};

#endif
