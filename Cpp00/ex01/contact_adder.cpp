/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_adder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:28:15 by aaugusto |        #+#    #+#             */
/*   Updated: 2025/11/30 18:19:40 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
bool	inputParser(const std::string &input) {
	bool onlySpaces = true;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] != ' ' && input[i] != '\t') {
			onlySpaces = false;
			break;
		}
	}
	if (onlySpaces)
		return (false);
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isalpha(input[i]) && input[i] != '-' && input[i] != ' ')
			return (false);
	}
	return (true);
}

std::string	askField(const	std::string &message, const	std::string	&errorMessage, int code) {
	std::string input;

	while (true)
	{
		std::cout << message;
		if (!std::getline(std::cin, input))
			return "";
		if (input.empty())
		{
			std::cout << errorMessage << std::endl;
			continue;
		}
		if ((code == FIRST_NAME || code == LAST_NAME) && !inputParser(input))
		{
			std::cout << "Invalid characters detected. Only letters, '-' and space are allowed." << std::endl;
			continue;
		}
		break;
	}
	return input;
}

void	contactAdder(Phonebook *Phonebook) {
	std::string name = askField(
		"Enter first name: ",
		"This field cannot be empty. Please enter a valid value.",
		FIRST_NAME
	);
	std::string lastName = askField(
		"Enter last name: ",
		"This field cannot be empty. Please enter a valid value.",
		LAST_NAME
	);
	std::string nickname = askField(
		"Enter nickname: ",
		"This field cannot be empty. Please enter a valid value.",
		NICKNAME
	);
	std::string phoneNumber = askField(
		"Enter phone number: ",
		"This field cannot be empty. Please enter a valid value.",
		PHONE_NUMBER
	);
	std::string secret = askField(
		"Enter darkest secret: ",
		"This field cannot be empty. Please enter a valid value.",
		SECRET
	);
	(void)Phonebook;
	//Phonebook->addContact(Name, LastName, Nickname, PhoneNumber, Secret);
}
