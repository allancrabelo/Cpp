/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:32:52 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/12 07:35:56 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	bool first = true;
	for (int i = 1; i < argc; i++)
	{
		char	*start = argv[i];
		char	*end = argv[i];

		while (*end)
			end++;
		while (end > start && std::isspace(*(end - 1)))
			end--;
		while (std::isspace(*start) && start < end)
			start++;
		if (start < end)
		{
			if (!first)
				std::cout << " ";
			first = false;
			for (char *p = start; p < end; p++)
				std::cout << char(std::toupper(*p));
		}
	}
	std::cout << std::endl;
	return 0;
}
