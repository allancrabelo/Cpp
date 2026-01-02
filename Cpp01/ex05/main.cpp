#include "Harl.hpp"

# define EXIT_SUCCESS	0

int	main(void)
{
	Harl	harl;
	
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("banana");	
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
