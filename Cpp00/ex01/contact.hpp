/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:54:37 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 01:00:53 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// Includes
#include <iostream>
#include <iomanip>

// Classes
class Contact
{
	private:
		std::string	_Name;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_Secret;
		time_t		_Created;
	public:
		Contact ();
		Contact(std::string first_name, std::string last_name, std::string nick_name,
				std::string phone_number, std::string darkest_secret);
		~Contact ();

		std::string	getName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		time_t		getCreated() const;
		std::string	getSecret() const;
};

#endif
