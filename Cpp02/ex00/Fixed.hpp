#ifndef		FIXED_HPP
# define	FIXED_HPP

// Includes:
# include <iostream>

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

	// Methods
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
