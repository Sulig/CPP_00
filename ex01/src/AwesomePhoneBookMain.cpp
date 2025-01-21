/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomePhoneBookMain.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:37:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/21 16:38:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./inc/PhoneBook.hpp"
//#include "./inc/Contact.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

/* Manage User Input */
/* The EOF is controlled by using:
*	- `std::getline(std::cin, userInput);` To get the input
*	- `std::cin.eof()` Gets the status of .eofbit
*/
void	manageUserInput()
{
	std::string	userInput;

	std::getline(std::cin, userInput);
	if (std::cin.eof())
	{
		std::cout << "EOF DETECTED. EXITING.." << std::endl;
		exit(0);
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
		std::cout << "> THIS ACTION DON'T EXIST. TRY ANOTHER ACTION!" << std::endl << std::endl;
}

int main()
{


	while (true)
	{
		std::cout << "[[ PHONEBOOK ] [ V 0.1 ]]" << std::endl;
		std::cout << "> Please enter an action | Options below" << std::endl;
		std::cout << "| ADD | SEARCH | EXIT |" << std::endl;
		manageUserInput();
	}
	return (0);
}
