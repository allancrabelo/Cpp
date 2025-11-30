/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:48:36 by aaugusto          #+#    #+#             */
/*   Updated: 2025/11/30 17:05:33 by aaugusto         ###   ########.fr       */
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
