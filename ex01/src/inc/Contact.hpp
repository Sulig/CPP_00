/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:40:45 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/21 17:26:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact:
{
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, int phone,
		std::string secret);
		~Contact();
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		int			phone;
		std::string	secret;
		void modifyDataContact();
};

#endif
