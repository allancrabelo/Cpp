/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:52:50 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 08:45:09 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// Includes
# include <iostream>
# include <string>
# include <iomanip>
# include <ctime>
# include "contact.hpp"

// Defines
# define MAX_CONTACTS 8

class Phonebook
{
	private:
		int	_NumInput;
	public:
		Contact contacts[MAX_CONTACTS];
		Phonebook();
		~Phonebook();

		//Methods
		void	addContactToPhonebook(std::string Name, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret);
		int		getNumInput();
};

#endif
