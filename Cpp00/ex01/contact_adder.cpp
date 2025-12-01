/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_adder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:28:15 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 09:10:14 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/**
 * @brief Validates the "darkest secret" input of a contact.
 * 
 * @details This function checks whether the provided input string
 * exceeds the maximum allowed length of 100 characters. If the input
 * is too long, it prints an error message indicating the actual
 * length and returns false. Otherwise, it returns true.
 * 
 * @param input The input string to validate.
 * @return bool Returns true if the input length is within limits,
 * false if it exceeds 100 characters.
 */
static bool inputDarkestSecretParser(const std::string &input) {
	if (input.length() > 100) {
		std::cout << "Invalid input detected. Limit of 100 characters. (Found "
				  << input.length() << ")." << std::endl;
		return (false);
	}
	return (true);
}

/**
 * @brief Validates the phone number input of a contact.
 * 
 * @details This function checks that the provided input string:
 * - Contains only digits, spaces, or tabs.
 * - Is not empty or composed solely of whitespace.
 * - Contains exactly 9 digits (ignoring spaces and tabs).
 * 
 * If any of these conditions are violated, an appropriate error
 * message is printed, and the function returns false. Otherwise,
 * it returns true.
 * 
 * @param input The phone number string to validate.
 * @return bool Returns true if the input is a valid phone number,
 * false otherwise.
 */

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

/**
 * @brief Validates the nickname input of a contact.
 * 
 * @details This function performs two main checks on the provided
 * input string:
 * 1. Ensures the input is not composed solely of spaces or tabs.
 * 2. Ensures all characters are either alphanumeric, a hyphen ('-'),
 *    or an underscore ('_').
 * 
 * If any invalid characters are found or the input is empty/whitespace,
 * an error message is printed, and the function returns false.
 * Otherwise, it returns true.
 * 
 * @param input The nickname string to validate.
 * @return bool Returns true if the input is valid, false otherwise.
 */
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

/**
 * @brief Validates the name input of a contact.
 * 
 * @details This function performs two main checks on the provided
 * input string:
 * 1. Ensures the input is not composed solely of spaces or tabs.
 * 2. Ensures all characters are either alphabetic letters, a hyphen ('-'),
 *    or a space.
 * 
 * If any invalid characters are found or the input is empty/whitespace,
 * an error message is printed, and the function returns false.
 * Otherwise, it returns true.
 * 
 * @param input The name string to validate.
 * @return bool Returns true if the input is valid, false otherwise.
 */
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

/**
 * @brief Prompts the user to input a field with validation.
 * 
 * @details This function repeatedly prompts the user with the
 * provided message until a valid input is received. The input is
 * validated based on the provided code:
 * - FIRST_NAME or LAST_NAME: validated using inputNameParser.
 * - NICKNAME: validated using inputNicknameParser.
 * - PHONE_NUMBER: validated using inputPhoneNumberParser.
 * - SECRET: validated using inputDarkestSecretParser.
 * 
 * If the input is empty or invalid, the errorMessage is printed
 * and the prompt repeats. If end-of-input is detected, the function
 * returns "__EOF__".
 * 
 * @param message The prompt message displayed to the user.
 * @param errorMessage The error message displayed for invalid input.
 * @param code An integer code indicating which validation to apply.
 * @return std::string The validated user input, or "__EOF__" on end-of-input.
 */
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
	std::string Name = askField(
		"Enter first name: ",
		"This field cannot be empty. Please enter a valid value.",
		FIRST_NAME
	);
	std::string LastName = askField(
		"Enter last name: ",
		"This field cannot be empty. Please enter a valid value.",
		LAST_NAME
	);
	std::string Nickname = askField(
		"Enter nickname: ",
		"This field cannot be empty. Please enter a valid value.",
		NICKNAME
	);
	std::string PhoneNumber = askField(
		"Enter phone number: ",
		"This field cannot be empty. Please enter a valid value.",
		PHONE_NUMBER
	);
	std::string Secret = askField(
		"Enter darkest secret: ",
		"This field cannot be empty. Please enter a valid value.",
		SECRET
	);
	std::cout << BOLD_GREEN "Contact was successfully added." RESET<< std::endl;
	Phonebook->addContactToPhonebook(Name, LastName, Nickname, PhoneNumber, Secret);
}
