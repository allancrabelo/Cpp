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

	// [Operators]:
	// Comparison Operators
	bool	operator>(const Fixed &copy);
	bool	operator<(const Fixed &copy);
	bool	operator>=(const Fixed &copy);
	bool	operator<=(const Fixed &copy);
	bool	operator==(const Fixed &copy);
	bool	operator!=(const Fixed &copy);

	// Arithmetic Operators
	Fixed	operator+(const Fixed &copy);
	Fixed	operator-(const Fixed &copy);
	Fixed	operator*(const Fixed &copy);
	Fixed	operator/(const Fixed &copy);

	// Increment & Decrement Operators
	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	// Public Overload
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // Overload

#endif
