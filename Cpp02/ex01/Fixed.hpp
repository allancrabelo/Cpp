#ifndef		FIXED_HPP
# define	FIXED_HPP

// Includes:
# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fractional = 8;
	public:
		Fixed(); // Default Constructor
		Fixed(const Fixed &copy); // Copy Constructor
		Fixed &operator=(const Fixed &copy); // Copy assignement operator overload
		~Fixed(); // Destructor

		Fixed(const int num);
		Fixed(const float num);

	// Methods
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // Overload

#endif
