/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:35:06 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 09:07:21 by aaugusto         ###   ########.fr       */
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
 * @details This function initializes a Phonebook object and manages
 * the command loop for user interaction. It first checks if the program
 * was executed with the correct number of arguments. If not, it prints
 * a usage error and exits with failure.
 * 
 * The function prints a banner and then enters an infinite loop to
 * process user commands. Supported commands are:
 * - "ADD": adds a new contact
 * - "SEARCH": searches existing contacts
 * - "EXIT": exits the application
 * 
 * If the command is not recognized, it informs the user and continues
 * the loop. The loop also terminates if end-of-input is detected.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Returns EXIT_SUCCESS on normal termination,
 * or EXIT_FAILURE if the program is run with incorrect arguments.
 */
int	main(int argc, char **argv)
{
	Phonebook	Phonebook;
	(void)argv;
	if (argc != 1)
	{
		std::cerr << BOLD_RED "[USAGE ERROR] ./phonebook" RESET << std::endl;
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
				searchContact(&Phonebook);
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

