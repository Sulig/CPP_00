/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomePhoneBookMain.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:37:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/20 19:30:38 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./inc/PhoneBook.hpp"
//#include "./inc/Contact.hpp"

#include <iostream>
#include <string>

void	manageUserInput(std::string userInput)
{
	if (userInput == "")
	{
		std::cout << "EOF DETECTED. EXITING.." << std::endl;
		exit (0);
	}
	else if (userInput == "ADD")
	{

	}
	else if (userInput == "SEARCH")
	{

	}
	else if (userInput == "EXIT")
	{
		std::cout << "ALL INFORMATION WILL BE CLEANED.. EXITING.." << std::endl;
		exit(0);
	}
	else
		std::cout << "> THIS ACTION DON'T EXIST. TRY ANOTHER ACTION!" << std::endl;
}

int main()
{
	std::string	userInput;

	while (true)
	{
		std::cout << "[[ PHONEBOOK ] [ V 0.1 ]]" << std::endl;
		std::cout << "> Please enter an action | Options below" << std::endl;
		std::cout << "| ADD | SEARCH | EXIT |" << std::endl;
		std::getline(std::cin, userInput);
		// CONTOL + d => CONTROLLED BY `std::getline(std::cin, userInput);` && `std::cin.eof()`
		std::cout << userInput << std::endl;
		manageUserInput(userInput);
	}
	return (0);
}
