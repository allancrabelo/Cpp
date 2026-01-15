#ifndef FIXED_HPP
# define FIXED_HPP

// Includes:
# include <iostream>

// Classes:
class	Fixed
{
	private:
		int	_value;
		static const int _fractional = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		Fixed(const int param);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
