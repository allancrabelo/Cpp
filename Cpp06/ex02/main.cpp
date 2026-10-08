#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random = std::rand() % 3;

	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else if (random == 2)
		return (new C);
	return(NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "The object's type is A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "The object's type is B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "The object's type is C" << std::endl;
	else
		std::cout << "Unknown object type." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The object's type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "The object's type is B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "The object's type is C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unknown object type." << std::endl;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cout << "usage: " << argv[0] << " (without arguments)" << std::endl;
		return (1);
	}

	std::srand(static_cast<unsigned>(time(NULL)));
	
	Base* base = generate();
	if (base == NULL)
		return (1);

	Base* anotherBase = generate();
	if (anotherBase == NULL)
	{
		delete base;
		return (1);
	}

	std::cout << "Identify with Pointer" << std::endl;
	identify(base);
	std::cout << std::endl;
	identify(anotherBase);

	std::cout << "Identify with Reference" << std::endl;
	identify(*base);
	std::cout << std::endl;
	identify(*anotherBase);
	
	delete base;
	delete anotherBase;

	return (0);
}