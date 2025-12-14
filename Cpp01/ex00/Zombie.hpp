/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:23:00 by aaugusto          #+#    #+#             */
/*   Updated: 2025/12/14 16:34:15 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

// Includes
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string	name);
		~Zombie();

	void	announce(void);
};
#endif