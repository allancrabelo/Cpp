#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vect;

	for (int i = 0; i < 10; i++)
		vect.push_back(i);

	for (int i = 0; i < 10; i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl << std::endl;

    try {
        std::cout << *easyfind(vect, 2) << std::endl;

		std::cout << *easyfind(vect, 42) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	return (0);
}