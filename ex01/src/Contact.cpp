/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:36:35 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/23 19:13:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Contact.hpp"

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, int phone, std::string secret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

int	Contact::isNull(Contact contact)
{
	return (contact.firstName.empty());
}

void	Contact::displayLargeStrings(std::string toPrint)
{
	if (toPrint.length() > 10)
	{
		//Declare special type of string that will recive the toPrint cuted with max width of 10
		std::stringstream	tmp;
		tmp << std::setw(10) << toPrint;
		// Convert the stream to string, so it will can be printed
		std::cout << tmp.str();
	}
	else
	{
		// How many spaces has to print?
		// Print spaces
		for (int spaces = 10 - toPrint.length(); spaces > 0; spaces--)
			std::cout << ' ';
		// Print it.
		std::cout << toPrint;
	}
}

void	Contact::displayInSearch(Contact contact, int index)
{
	std::cout << "         " << index;
	displayLargeStrings(contact.firstName);
	std::cout << "|";
	displayLargeStrings(contact.lastName);
	std::cout << "|";
	displayLargeStrings(contact.nickname);
	std::cout << "|" << std::endl;
}

void	Contact::displayAll(Contact contact)
{
	std::cout << "[ Contact information ]" << std::endl;
	std::cout << "|| First name:\t" << contact.firstName << std::endl;
	std::cout << "|| Last name: \t" << contact.lastName << std::endl;
	std::cout << "|| Nickname:  \t" << contact.nickname << std::endl;
	std::cout << "|| Phone:\t\t\t" << contact.phone << std::endl;
	std::cout << "|| Darkest Secret:\t" << contact.secret << std::endl;
	std::cout << "~ ------------------" << std::endl << std::endl;
}
