#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "==================== EX03 TESTS ====================" << std::endl;
	Intern	intern;
	Bureaucrat	boss("Boss", 1);
	AForm	*form;

	{
		std::cout << "\n[TEST 1] Create robotomy request form" << std::endl;
		try
		{
			form = intern.makeForm("robotomy request", "Bender");
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Unexpected error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n[TEST 2] Create shrubbery creation form" << std::endl;
		try
		{
			form = intern.makeForm("shrubbery creation", "garden");
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Unexpected error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n[TEST 3] Create presidential pardon form" << std::endl;
		try
		{
			form = intern.makeForm("presidential pardon", "Arthur Dent");
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Unexpected error: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n[TEST 4] Invalid form name" << std::endl;
		try
		{
			form = intern.makeForm("coffee request", "Office");
			delete form;
		}
		catch (const std::exception &e)
		{
			std::cout << "Expected error caught: " << e.what() << std::endl;
		}
	}
	return (0);
}