/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:36:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/24 17:00:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void) { return ;}
PhoneBook::~PhoneBook(void) { return ; }

PhoneBook PhoneBook::startContactIndex(PhoneBook phoneBook)
{
	phoneBook.lastContactIndex = 0;
	return (phoneBook);
}

/* Remove innecesary block of chars */
std::string	PhoneBook::trim(std::string str)
{
	if (std::cin.eof())
		return (str);
	str.erase(0, str.find_first_not_of(" \t\v\r\f\n"));
	str.erase(str.find_last_not_of(" \t\v\r\f\n") + 1);
	return (str);
}

int	PhoneBook::atoi(std::string str)
{
	int		cnt;
	int		sign;
	int		find;

	find = 0;
	cnt = -1;
	sign = 1;
	while (str[++cnt] < 33)
		if ((str[cnt] < 9 || str[cnt] > 13) && str[cnt] != ' ')
			return (-1);
	if (!(str[cnt] >= '0' && str[cnt] <= '9'))
		return (-1);
	if (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			sign *= -1;
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		find *= 10;
		find += str[cnt] - '0';
		cnt++;
	}
	return (find * sign);
}

int	PhoneBook::lastContact(PhoneBook phoneBook)
{
	for (int i = 0; i < 8; i++)
		if (phoneBook.contacts[i].isNull(phoneBook.contacts[i]))
			return (i);
	return (8);
}

std::string	PhoneBook::manageInput(void)
{
	std::string	userInput;

	do {
		std::getline(std::cin, userInput);
		userInput = trim(userInput);
		if (std::cin.eof())
		{
			std::cout << "EOF DETECTED. EXITING.." << std::endl;
			exit(0);
		}
		else
		{
			if (!userInput.length())
				std::cout << "Please introduce something!" << std::endl;
			else
				break;
		}
	} while (42);
	return (userInput);
}

void	PhoneBook::showContacts(PhoneBook phoneBook)
{
	std::cout << "[ Actual Contacts ]" << std::endl;
	if (phoneBook.contacts[0].isNull(phoneBook.contacts[0]))
		std::cout << "- Oh! No contacts! -" << std::endl;
	else //Prompt Contact list
	{
		int index;
		std::string input;

		std::cout << "     Index|First Name| Last Name|  Nickname ~//" << std::endl;
		for (int i = 0; i < phoneBook.lastContact(phoneBook); i++) {
			if (i >=8 || phoneBook.contacts[i].isNull(phoneBook.contacts[i]))
				break ;
			phoneBook.contacts[i].displayInSearch(phoneBook.contacts[i], i);
		}
		std::cout << "[//*************************//]" << std::endl << std::endl;
		std::cout << "To see more details of some contact, insert the index number" << std::endl;
		input = manageInput();
		index = atoi(input);
		if (index >= 0 && index < phoneBook.lastContact(phoneBook))
			phoneBook.contacts[index].displayAll(phoneBook.contacts[index]);
		else
			std::cout << "Invalid index" << std::endl;
	}
}

PhoneBook	PhoneBook::addContact(PhoneBook phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	tmPhone;
	int			phone;
	std::string	secret;
	Contact		contact;

	std::cout << "[ Adding a new contact ]" << std::endl;
	std::cout << "> Add the First name: " << std::endl;
	firstName = manageInput();
	std::cout << "> Add the Last name: " << std::endl;
	lastName = manageInput();
	std::cout << "> Add the Nickname: " << std::endl;
	nickname = manageInput();
	std::cout << "> Add the Phone number: " << std::endl;
	tmPhone = manageInput();
	phone = atoi(tmPhone);
	while (phone < 0)
	{
		std::cout << "Invalid phone number" << std::endl;
		std::cout << "> Add a VALID Phone number: " << std::endl;
		tmPhone = manageInput();
		phone = atoi(tmPhone);
	}
	std::cout << "> Add the Darkest secret: " << std::endl;
	secret = manageInput();
	std::cout << "[> Creating contact.. :) ]" << std::endl;

	contact = Contact(firstName, lastName, nickname, phone, secret);

	// Add contact to the phonebook
	if (phoneBook.lastContactIndex < 8)
		phoneBook.contacts[phoneBook.lastContactIndex++] = contact;
	/* If the phonebook is full, remove the last contact
		and add the new one to first position ~
	*/
	else
	{
		phoneBook.contacts[0] = contact;
		phoneBook.lastContactIndex = 1;
	}
	std::cout << "[ Contact added! ]" << std::endl << std::endl;
	return (phoneBook);
}
