/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:36:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/23 18:00:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { return ;}
PhoneBook::~PhoneBook() {
	std::cout << "No more contacts? 0_)0" << std::endl;
	return ;}

/* Remove innecesary block of chars */
std::string	PhoneBook::trim(std::string str)
{
	str.erase(0, str.find_first_not_of(" \t\v\r\f\n"));
	str.erase(str.find_last_not_of(" \t\v\r\f\n") + 1);
	return (str);
}

std::string	PhoneBook::manageInput(void)
{
	std::string	userInput;

	do {
		std::getline(std::cin, userInput);
		if (std::cin.eof() || !userInput.length())
			std::cout << "Please introduce something!" << std::endl;
		userInput = trim(userInput);
		if (!userInput.length())
			std::cout << "Please introduce something!" << std::endl;
		else
			break;
	} while (42);
	return (userInput);
}

void	PhoneBook::showContacts(PhoneBook phoneBook)
{
	std::cout << "[ Actual Contacts ]" << std::endl;
	if (!phoneBook.contacts)
		std::cout << "- Oh! No contacts! -" << std::endl;
	else //Prompt Contact list
	{
		int index;
		std::string input;

		std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
		for (int i = 0; i < phoneBook.lastContact; i++) {
			phoneBook.contacts[i].displayInSearch(phoneBook.contacts[i], i);
		}
		std::cout << "[//*************************//]" << std::endl << std::endl;
		std::cout << "To see more details of some contact, insert the index number" << std::endl;
		input = manageInput();
		index = std::stoi(input);
		if (index >= 0 && index < phoneBook.lastContact)
			phoneBook.contacts[index].displayAll(phoneBook.contacts[index]);
		else
			std::cout << "Invalid index" << std::endl;
	}
}

void	PhoneBook::addContact(PhoneBook phoneBook)
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
	phone = std::stoi(tmPhone);
	while (!(phone >= 0))
	{
		std::cout << "Invalid phone number" << std::endl;
		std::cout << "> Add a VALID Phone number: " << std::endl;
		tmPhone = manageInput();
		phone = std::stoi(tmPhone);
	}
	std::cout << "> Add the Darkest secret: " << std::endl;
	secret = manageInput();
	std::cout << "[> Creating contact.. :) ]" << std::endl;
	contact = Contact(firstName, lastName, nickname, phone, secret);

	// Add contact to the phonebook
	if (lastContact < 8)
	{
		phoneBook.contacts[lastContact] = contact;
		lastContact++;
	}
	/* If the phonebook is full, remove the last contact
		and add the new one to first position ~
	*/
	else
	{
		for (int i = 0; i < 7; i++)
			phoneBook.contacts[i] = phoneBook.contacts[i + 1];
		phoneBook.contacts[0] = contact;
	}
	std::cout << "[ Contact added! ]" << std::endl;
}
