#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int value);

# include "easyfind.tpp"

#endif