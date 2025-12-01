/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:41:04 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 09:16:20 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/**
 * @brief Prints a formatted string for table display.
 * 
 * @details This function formats a string to fit within 10 characters.
 * If the string exceeds 10 characters, it is truncated and a dot ('.')
 * is appended. The string is then printed with a width of 10 characters
 * followed by a '|' character. Optionally, a newline can be printed.
 * 
 * @param str The string to format and print.
 * @param newline If true, a newline is printed after the string.
 */
static void print_data(std::string str, bool newline) {
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::setfill(' ') << std::setw(10) << str << "|";
	if (newline)
		std::cout << std::endl;
}

/**
 * @brief Prints the header of the contacts table.
 * 
 * @details This function prints a formatted header row for the
 * contacts table, including the columns: Index, First Name,
 * Last Name, and Nick Name. Decorative lines are printed above
 * and below the header for visual clarity.
 */
static void print_header(void) {
	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|";
	print_data("Index", false);
	print_data("First Name", false);
	print_data("Last Name", false);
	print_data("Nick Name", true);
	std::cout << "|-------------------------------------------|" << std::endl;
}

/**
 * @brief Prints all contacts in the Phonebook in a table format.
 * 
 * @details This function iterates through all contacts stored in
 * the Phonebook and prints their index, first name, last name,
 * and nickname in a formatted table. Each column is aligned and
 * truncated if necessary.
 * 
 * @param Phonebook Pointer to the Phonebook object containing contacts.
 */
static void print_all_contacts(Phonebook *Phonebook) {
	for (int i = 0; i < Phonebook->getNumInput(); i++)
	{
		std::cout << "|";
		std::cout << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		print_data(Phonebook->contacts[i].getName(), false);
		print_data(Phonebook->contacts[i].getLastName(), false);
		print_data(Phonebook->contacts[i].getNickName(), true);
	}
}

/**
 * @brief Prints detailed information of a single contact.
 * 
 * @details This function prints all fields of a Contact object:
 * first name, last name, nickname, phone number, and darkest secret.
 * Each field is labeled and colored for clarity.
 * 
 * @param Contact The Contact object whose information will be printed.
 */
static void print_contact(Contact Contact) {
	std::cout << std::endl << MAGENTA << "First Name: " << RESET << Contact.getName() << std::endl;
	std::cout << MAGENTA << "Last Name: " << RESET << Contact.getLastName() << std::endl;
	std::cout << MAGENTA << "NickName: " << RESET << Contact.getNickName() << std::endl;
	std::cout << MAGENTA << "Phone Number: " << RESET << Contact.getPhoneNumber() << std::endl;
	std::cout << MAGENTA << "Darkest Secret: " << RESET << Contact.getSecret() << std::endl;
}

/**
 * @brief Converts a string to lowercase.
 * 
 * @details This function iterates over each character of the input
 * string and converts it to its lowercase equivalent using std::tolower.
 * The resulting lowercase string is returned.
 * 
 * @param s The input string to convert.
 * @return std::string A new string with all characters converted to lowercase.
 */
static std::string toLowerCase(std::string s) {
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::tolower(s[i]);
	return s;
}

/**
 * @brief Safely converts a string of digits to an integer.
 * 
 * @details This function parses the input string and converts it
 * to an integer. If any character in the string is not a digit,
 * the function returns -1 to indicate an invalid input. Otherwise,
 * it returns the integer value represented by the string.
 * 
 * @param s The string to convert.
 * @return int The integer value of the string, or -1 if the string
 * contains non-digit characters.
 */
static int safeAtoi(std::string s) {
	int result = 0;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return -1;
		result = result * 10 + (s[i] - '0');
	}
	return result;
}

/**
 * @brief Searches and displays contacts in the Phonebook.
 * 
 * @details This function allows the user to search for contacts
 * stored in the Phonebook. If no contacts exist, it prints a warning.
 * 
 * The function first prints a formatted table of all contacts.
 * Then, it prompts the user to choose between:
 * 1. Viewing a contact by its index.
 * 2. Performing an advanced search across any contact field.
 * 
 * For the index option, the user is prompted to enter a valid index.
 * For the advanced search, the user provides a query string, which
 * is matched case-insensitively against all contact fields. Matching
 * contacts are displayed with their full details. If no match is found,
 * an appropriate message is shown.
 * 
 * Invalid inputs are handled gracefully with informative messages.
 * 
 * @param Phonebook Pointer to the Phonebook object containing contacts.
 */
void searchContact(Phonebook *Phonebook) {
	if (Phonebook->getNumInput() < 1) {
		std::cout << YELLOW << "Please Add a Contact before trying to Search" 
				  << RESET << std::endl;
		return;
	}
	print_header();
	print_all_contacts(Phonebook);
	std::cout << "|-------------------------------------------|" << std::endl;
	std::string option;
	std::cout << CYAN <<
		"\nChoose an option:\n"
		" 1 - View contact by INDEX\n"
		" 2 - Advanced Search (any field)\n"
		"Your choice: "
	<< RESET;
	std::getline(std::cin, option);
	if (option == "1") {
		std::string input;
		int index;
		std::cout << BLUE << "Enter index: " << RESET;
		std::getline(std::cin, input);
		index = safeAtoi(input);
		if (index > 0 && index <= Phonebook->getNumInput())
			print_contact(Phonebook->contacts[index - 1]);
		else
			std::cout << RED << "Invalid index!" << RESET << std::endl;
	}
	else if (option == "2") {
		std::string query;
		bool found = false;
		std::cout << BLUE << "Search query: " << RESET;
		std::getline(std::cin, query);
		std::string q = toLowerCase(query);
		for (int i = 0; i < Phonebook->getNumInput(); i++)
		{
			Contact &C = Phonebook->contacts[i];
			std::string name = toLowerCase(C.getName());
			std::string lname = toLowerCase(C.getLastName());
			std::string nick = toLowerCase(C.getNickName());
			std::string phone = toLowerCase(C.getPhoneNumber());
			std::string secret = toLowerCase(C.getSecret());

			if (name.find(q) != std::string::npos ||
				lname.find(q) != std::string::npos ||
				nick.find(q) != std::string::npos ||
				phone.find(q) != std::string::npos ||
				secret.find(q) != std::string::npos) {
				std::cout << GREEN << "\n[Match found at index " << i + 1 << "]" 
						  << RESET << std::endl;
				print_contact(C);
				found = true;
			}
		}
		if (!found)
			std::cout << YELLOW << "\nNo contacts matched your search." 
					  << RESET << std::endl;
	} else {
		std::cout << YELLOW << "Invalid option." << RESET << std::endl;
	}
}
