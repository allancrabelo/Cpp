/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:35:06 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/30 16:57:38 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/**
 * @brief Prints the banner of the PhoneBook application.
* 
* @return * void 
*/
void bannerPrinter(void)
{
	std::cout << std::endl;
	std::cout << "░█████████  ░██     ░██   ░██████   ░███    ░██ ░██████████ ░████████     ░██████     ░██████   ░██     ░██ " << std::endl;
	std::cout << "░██     ░██ ░██     ░██  ░██   ░██  ░████   ░██ ░██         ░██    ░██   ░██   ░██   ░██   ░██  ░██    ░██  " << std::endl;
	std::cout << "░██     ░██ ░██     ░██ ░██     ░██ ░██░██  ░██ ░██         ░██    ░██  ░██     ░██ ░██     ░██ ░██   ░██   " << std::endl;
	std::cout << "░█████████  ░██████████ ░██     ░██ ░██ ░██ ░██ ░█████████  ░████████   ░██     ░██ ░██     ░██ ░███████    " << std::endl;
	std::cout << "░██         ░██     ░██ ░██     ░██ ░██  ░██░██ ░██         ░██     ░██ ░██     ░██ ░██     ░██ ░██   ░██   " << std::endl;
	std::cout << "░██         ░██     ░██  ░██   ░██  ░██   ░████ ░██         ░██     ░██  ░██   ░██   ░██   ░██  ░██    ░██  " << std::endl;
	std::cout << "░██         ░██     ░██   ░██████   ░██    ░███ ░██████████ ░█████████    ░██████     ░██████   ░██     ░██ " << std::endl;
	std::cout << std::endl;
}

/**
 * @brief Normalizes the input string to uppercase.
 *
 * @param input The input string to be normalized.
 */
void inputNormalizer(std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
		input[i] = std::toupper(input[i]);
}

/**
 * @brief Main function of the PhoneBook application.
 * 
 * @details This function initializes the PhoneBook application,
 * displays a banner, and enters a command loop to process user input.
 * It recognizes the "EXIT" command to terminate the application.
 * If the command is not recognized, it informs the user.
 * @param argc 
 * @param argv 
 * @return * int 
 */
int	main(int argc, char **argv)
{
	Phonebook	Phonebook;
	(void)argv;
	if (argc != 1)
	{
		std::cerr << "[USAGE ERROR] ./phonebook" << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		std::string input;
		bannerPrinter();
		while (1)
		{
			std::cout << "Enter command: ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << std::endl;
				break;
			}
			inputNormalizer(input);
			if (input.empty())
				continue ;
			else if (input == "ADD")
				contactAdder(&Phonebook);
			else if (input == "SEARCH")
				std::cout << GREEN "[INFO] SEARCH command recognized. (Functionality not implemented yet)" RESET << std::endl;
			else if (input == "EXIT")
			{
				std::cout << CYAN "Exiting PhoneBook. Goodbye!" RESET << std::endl;
				break ;
			}
			else
				std::cout << YELLOW "[INFO] Command '" << input << "' not recognized." RESET << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}

