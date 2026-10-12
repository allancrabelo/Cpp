#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class	Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array();

		T				&operator[](unsigned int n);
		const T			&operator[](unsigned int n) const;
		unsigned int	size(void) const;

		class OutOfBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

# include "Array.tpp"

#endif