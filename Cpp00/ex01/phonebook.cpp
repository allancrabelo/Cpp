/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:48:36 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 09:11:13 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() {
	_NumInput = 0;
}

Phonebook::~Phonebook() {
}

int	Phonebook::getNumInput() {
	return (_NumInput);
}

/**
 * @brief Finds the index of the oldest contact in the array.
 * 
 * @details This function iterates through the array of contacts
 * and identifies the contact with the earliest creation timestamp.
 * The index of this oldest contact is returned. This is useful
 * when the Phonebook has reached its maximum capacity and a contact
 * needs to be overwritten.
 * 
 * @param contacts Array of Contact objects.
 * @return int Index of the oldest contact in the array.
 */
int	search_oldest_entry(Contact contacts[MAX_CONTACTS])
{
	int	oldest;

	oldest = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].getCreated() < contacts[oldest].getCreated())
			oldest = i;
	}
	return (oldest);
}

/**
 * @brief Adds a new contact to the Phonebook.
 * 
 * @details This function creates a new Contact object using the
 * provided details and stores it in the Phonebook. If the
 * Phonebook has not reached its maximum capacity, the contact
 * is added to the next available slot. If the Phonebook is full,
 * the oldest contact is overwritten by the new contact.
 * 
 * @param Name First name of the contact.
 * @param LastName Last name of the contact.
 * @param Nickname Nickname of the contact.
 * @param PhoneNumber Phone number of the contact.
 * @param Secret Darkest secret of the contact.
 */
void	Phonebook::addContactToPhonebook(std::string Name, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret)
{
	if (_NumInput < MAX_CONTACTS)
	{
		contacts[_NumInput] = Contact(Name, LastName, Nickname, PhoneNumber, Secret);
		_NumInput++;
	}
	else
		contacts[search_oldest_entry(contacts)] = Contact(Name, LastName, Nickname, PhoneNumber, Secret);
}