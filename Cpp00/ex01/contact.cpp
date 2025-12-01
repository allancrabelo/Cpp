/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:14:29 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 01:00:49 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//Constructor
Contact::Contact() {
}

//Parametrized Constructor
Contact::Contact(std::string Name, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret) {
	_Name = Name;
	_LastName = LastName;
	_Nickname = Nickname;
	_PhoneNumber = PhoneNumber;
	_Secret = Secret;
	time (&_Created);
}

// Destructor
Contact::~Contact() {
}

//Getters | Fetchers
std::string	Contact::getName() const
{
	return (_Name);
}

std::string	Contact::getLastName() const
{
	return (_LastName);
}

std::string	Contact::getNickName() const
{
	return (_Nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (_PhoneNumber);
}

std::string	Contact::getSecret() const
{
	return (_Secret);
}

time_t		Contact::getCreated() const
{
	return (_Created);
}
