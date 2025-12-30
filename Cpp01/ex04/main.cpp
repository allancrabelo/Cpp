#include "main.hpp"

int	main(int argc, char **argv)
{
	if (!programParser(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
