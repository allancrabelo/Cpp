/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:52:50 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/01 08:47:24 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

// Libraries
# include <iostream>
# include <string>
# include <iomanip>
# include <ctime>
# include <limits>
# include <cstdlib>

# include "colors.hpp"
# include "contact.hpp"
# include "phonebook.hpp"

// Defines
# define FIRST_NAME 0
# define LAST_NAME 1
# define NICKNAME 2
# define PHONE_NUMBER 3
# define SECRET 4
# define PARSER_ERROR "[INPUT ERROR] Invalid input. Please try again."

void	contactAdder(Phonebook *Phonebook);
void	searchContact(Phonebook *Phonebook);
void	bannerPrinter(void);

#endif
