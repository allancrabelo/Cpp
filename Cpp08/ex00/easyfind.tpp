template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename	T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw	(std::runtime_error("[ERROR] Value not found."));
	
	return (iter);
}