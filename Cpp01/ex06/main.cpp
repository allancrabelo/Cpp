#include "Harl.hpp"

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

# define ERR_USAGE_ARG	"[ERROR 100] Usage Error: ./harlFilter <filter> [DEBUG, INFO, WARNING or ERROR]"

static	std::string stringCapitalizer(std::string str)
{
	std::string	capitalizedString = str;

	for (size_t	i = 0; i < str.length(); i++)
		capitalizedString[i] = toupper(str[i]);		
	return (capitalizedString);
}

int	main(int argc, char **argv)
{
	std::string	complaint;
	
	switch (argc)
	{
		case 2: {	
			Harl	harl;
			complaint = stringCapitalizer(argv[1]);
			harl.complain(complaint);
			return (EXIT_SUCCESS);
		}
		default:
			std::cout << ERR_USAGE_ARG << std::endl;	
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
