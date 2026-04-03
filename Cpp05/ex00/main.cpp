#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "       BUREAUCRAT EXCEPTION TESTER       " << std::endl;
	std::cout << "=========================================\n" << std::endl;

	std::cout << "\033[33m========== SUBJECT MANDATORY TEST =========\033[0m\n" << std::endl;
	std::cout << "\033[34m[TEST 1] Valid Bureaucrat test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	a("Max Weber", 42);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 2] Grade Too Low test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b("Max Weber", 15000);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 3] Grade Too High test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	c("Max Weber", 0);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 4] Valid increment test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	d("Max Weber", 42);
		std::cout << d << std::endl;
		d.increment();
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 5] Invalid increment test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	e("Max Weber", 1);
		std::cout << e << std::endl;
		e.increment();
		std::cout << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 6] Valid decrement test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	f("Max Weber", 42);
		std::cout << f << std::endl;
		f.decrement();
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 5] Invalid decrement test\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	g("Max Weber", 150);
		std::cout << g << std::endl;
		g.decrement();
		std::cout << g << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}