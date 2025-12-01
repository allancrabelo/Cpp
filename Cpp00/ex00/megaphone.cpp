/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:32:52 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 10:28:23 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

int main(int argc, char **argv)
{
	bool printed = false;

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		size_t start = arg.find_first_not_of(" \t");
		size_t end = arg.find_last_not_of(" \t");
		if (start == std::string::npos)
			continue;
		arg = arg.substr(start, end - start + 1);
		for (size_t j = 0; j < arg.length(); j++)
			arg[j] = std::toupper(arg[j]);
		if (printed)
			std::cout << " ";
		std::cout << arg;
		printed = true;
	}
	if (!printed)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}



