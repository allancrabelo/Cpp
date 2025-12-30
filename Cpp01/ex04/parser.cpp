#include "main.hpp"

int numberOfArguments(int argc)
{
	if (argc != 4)
	{
	
		std::cerr << "[ERROR 100] Usage Error: ./sed <filename> <S1> <S2>" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	programParser(int argc, char **argv)
{
	(void)argv;
	if (!numberOfArguments(argc))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
