#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << "Array Default Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	std::cout << "Array numbered Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size)
{
	std::cout << "Array Copy constructor called" << std::endl;
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& copy)
{
	std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		T *newArray = NULL;

		if (copy._size > 0)
		{
			newArray = new T[copy._size]();
			for (unsigned int i = 0; i < copy._size; i++)
				newArray[i] = copy._array[i];
		}
		delete[] _array;
		_array = newArray;
		_size = copy._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Destrutcor Called" << std::endl;
	delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw OutOfBounds();
	return (_array[n]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (n >= _size)
		throw OutOfBounds();
	return (_array[n]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return ("Index out of bounds");
}