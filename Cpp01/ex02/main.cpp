// Includes:
#include <iostream>
#include <string>

// Defines:
#define EXIT_SUCCESS	0

/*
* @breaf that funtion should contain: 
*	1 - string initialized with "HI THIS IS BRAIN"
*	2 - A pointer to the string
*	3 - A reference to that string
*	4 - Print expeted outputs.
* @return EXIT_SUCCESS
*/
int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The memory adress of the string variable: " << &string << std::endl;
	std::cout << "The memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory adress held by stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl;

	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << string << std::endl;
	
	return (EXIT_SUCCESS);
}
