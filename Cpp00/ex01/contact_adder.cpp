/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_adder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:28:15 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 01:00:42 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static bool inputDarkestSecretParser(const std::string &input) {
	if (input.length() > 100) {
		std::cout << "Invalid input detected. Limit of 100 characters. (Found "
				  << input.length() << ")." << std::endl;
		return (false);
	}
	return (true);
}

static bool inputPhoneNumberParser(const std::string &input) {
	int digitCount = 0;
	bool hasNonSpace = false;

	for (size_t i = 0; i < input.length(); i++) {
		char c = input[i];
		if (c == ' ' || c == '\t') {
			continue;
		}
		hasNonSpace = true;
		if (std::isdigit(c)) {
			digitCount++;
		} else {
			std::cout << "Invalid character: '" << c
					  << "' (Only digits, spaces, and tabs allowed)." << std::endl;
			return (false);
		}
	}
	if (!hasNonSpace) {
		std::cout << "Phone number cannot be empty or only spaces." << std::endl;
		return (false);
	}
	if (digitCount != 9) {
		std::cout << "Phone number must contain exactly 9 digits. (Found "
				  << digitCount << ")." << std::endl;
		return (false);
	}
	return (true);
}



static bool inputNicknameParser(const std::string &input) {
	bool onlySpaces = true;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] != ' ' && input[i] != '\t') {
			onlySpaces = false;
			break;
		}
	}
	if (onlySpaces) {
		std::cout << "Invalid input detected. Only spaces or tabs" << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++) {
		char c = input[i];
		bool ok =
			(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9') ||
			c == '-' ||
			c == '_';
		if (!ok) {
			std::cout << "Invalid character: '" << c << "' (Only alphanumerics and '-' or '_'). "<< std::endl;
			return (false);
		}
	}
	return (true);
}

static bool	inputNameParser(const std::string &input) {
	bool onlySpaces = true;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] != ' ' && input[i] != '\t') {
			onlySpaces = false;
			break;
		}
	}
	if (onlySpaces) {
		std::cout << "Invalid input detected. Only spaces or tabs" << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isalpha(input[i]) && input[i] != '-' && input[i] != ' ') {
			std::cout << "Invalid characters detected. Only letters, '-' and space are allowed." << std::endl;
			return (false);
		}
	}
	return (true);
}

std::string	askField(const	std::string &message, const	std::string	&errorMessage, int code) {
	std::string input;

	while (true)
	{
		std::cout << message;
		if (!std::getline(std::cin, input))
			return ("__EOF__");
		if (input.empty())
		{
			std::cout << errorMessage << std::endl;
			continue ;
		}
		if ((code == FIRST_NAME || code == LAST_NAME) && !inputNameParser(input))
			continue ;
		if (code == NICKNAME && !inputNicknameParser(input))
			continue ;
		if (code == PHONE_NUMBER && !inputPhoneNumberParser(input))
			continue ;
		if (code == SECRET && !inputDarkestSecretParser(input))
			continue ;
		break ;
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
	std::cout << BOLD_GREEN "Contact was successfully added." RESET<< std::endl;
	(void)Phonebook;
	//Phonebook->addContact(Name, LastName, Nickname, PhoneNumber, Secret);
}
