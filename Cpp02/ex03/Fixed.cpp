#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int	num)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = num << _fractional;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(num * (1 << _fractional)));
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float> (_value) / (1 << _fractional));
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed &copy)
{
	return (this->_value > copy._value);
}

bool	Fixed::operator<(const Fixed &copy)
{
	return (this->_value < copy._value);
}

bool	Fixed::operator>=(const Fixed &copy)
{
	return (this->_value >= copy._value);
}

bool	Fixed::operator<=(const Fixed &copy)
{
	return (this->_value >= copy._value);
}

bool	Fixed::operator==(const Fixed &copy)
{
	return (this->_value >= copy._value);
}

bool	Fixed::operator!=(const Fixed &copy)
{
	return (this->_value >= copy._value);
}

Fixed	Fixed::operator+(const Fixed &copy)
{
	return (this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed &copy)
{
	return (this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy)
{
	return (this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy)
{
	return (this->toFloat() / copy.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	++_value;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--_value;
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}
