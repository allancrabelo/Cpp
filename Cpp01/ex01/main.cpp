#include "Zombie.hpp"

static int	numberParser(char **argv)
{
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		if (!isdigit(argv[1][i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	inputParser(int argc, char **argv)
{
	int	n;

	if (argc != 2)
		return (std::cerr << ERR_NUMBER_ARGUMENTS << std::endl, EXIT_FAILURE);
	if (numberParser(argv))
		return (std::cerr << ERR_INPUT_NOT_NUMBER << std::endl , EXIT_FAILURE);
	n = atoi(argv[1]);
	if (n <= 0)
		return (std::cerr << ERR_INPUT_NEGATIVE << std::endl , EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	Zombie	*horde;
	int		N;
	
	N = 0;
	if (inputParser(argc,argv))
		return (EXIT_FAILURE);
	N = atoi(argv[1]);
	horde = zombieHorde(N, "banana zombie");

	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i + 1 << " -> ";
		horde[i].announce();
	}
	
	delete[] horde;
	return (EXIT_SUCCESS);
}
