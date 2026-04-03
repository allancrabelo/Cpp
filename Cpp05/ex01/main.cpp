#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "=========================================" << std::endl;
	std::cout << "                SUBJECT TESTS            " << std::endl;
	std::cout << "=========================================\n" << std::endl;

	std::cout << "\033[34m[TEST 1] Valid Form construction\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Form	leaveRequest("LeaveRequest", 42, 21);
		std::cout << leaveRequest << std::endl;
		std::cout << "gradeToSign: " << leaveRequest.getGradeToSign()
			<< ", gradeToExecute: " << leaveRequest.getGradeToExecute() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 2] Form grade too high on construction\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Form	invalidHigh("InvalidHigh", 0, 42);
		std::cout << invalidHigh << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 3] Form grade too low on construction\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Form	invalidLow("InvalidLow", 42, 151);
		std::cout << invalidLow << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 4] beSigned success\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	alice("Alice", 30);
		Form		contract("Contract", 50, 10);
		std::cout << contract << std::endl;
		contract.beSigned(alice);
		std::cout << contract << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 5] beSigned failure (grade too low)\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 100);
		Form		nda("NDA", 75, 40);
		std::cout << nda << std::endl;
		nda.beSigned(bob);
		std::cout << nda << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 6] Bureaucrat::signForm success path\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	chief("Chief", 10);
		Form		report("Report", 20, 15);
		chief.signForm(report);
		std::cout << report << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[TEST 7] Bureaucrat::signForm failure path\033[0m" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	intern("Intern", 140);
		Form		secret("SecretFile", 20, 5);
		intern.signForm(secret);
		std::cout << secret << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}