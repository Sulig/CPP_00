/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomePhoneBookMain.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:37:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/24 16:51:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/PhoneBook.hpp"
#include "./inc/Contact.hpp"

/* Manage User Input */
/* The EOF is controlled by using:
*	- `std::getline(std::cin, userInput);` To get the input
*	- `std::cin.eof()` Gets the status of .eofbit
*/
PhoneBook	manageUserInput(PhoneBook phoneBook)
{
	std::string	userInput;

	std::getline(std::cin, userInput);
	if (std::cin.eof())
	{
		std::cout << "EOF DETECTED. EXITING.." << std::endl;
		exit(0);
	}
	else if (userInput == "ADD")
		phoneBook = phoneBook.addContact(phoneBook);
	else if (userInput == "SEARCH")
		phoneBook.showContacts(phoneBook);
	else if (userInput == "EXIT")
	{
		std::cout << "No more contacts? @_)@" << std::endl;
		std::cout << "ALL INFORMATION WILL BE CLEANED.. EXITING.." << std::endl;
		exit(0);
	}
	else
		std::cout << "> THIS ACTION DON'T EXIST. TRY ANOTHER ACTION!" << std::endl << std::endl;
	return (phoneBook);
}

int main()
{
	PhoneBook	phoneBook;

	std::cout << "[[ PHONEBOOK ] [ V 0.6 ]]" << std::endl;
	phoneBook = phoneBook.startContactIndex(phoneBook);
	while (true)
	{
		std::cout << "> Please enter an action | Options below" << std::endl;
		std::cout << "| ADD | SEARCH | EXIT |" << std::endl;
		phoneBook = manageUserInput(phoneBook);
	}
	return (0);
}
