#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "==================== EX02 TESTS ====================" << std::endl;

	{
		std::cout << "\n[TEST 1] Shrubbery: execute without signing" << std::endl;
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");
		boss.executeForm(shrub);
	}

	{
		std::cout << "\n[TEST 2] Shrubbery: sign + execute success" << std::endl;
		Bureaucrat gardener("Gardener", 1);
		ShrubberyCreationForm shrub("garden");
		gardener.signForm(shrub);
		gardener.executeForm(shrub);
		std::cout << "Check generated file: garden_shrubbery" << std::endl;
	}

	{
		std::cout << "\n[TEST 3] Robotomy: signer too low" << std::endl;
		Bureaucrat intern("Intern", 150);
		RobotomyRequestForm robo("Bender");
		intern.signForm(robo);
	}

	{
		std::cout << "\n[TEST 4] Robotomy: execute grade too low" << std::endl;
		Bureaucrat signer("Signer", 72);
		Bureaucrat executor("Executor", 46);
		RobotomyRequestForm robo("Marvin");
		signer.signForm(robo);
		executor.executeForm(robo);
	}

	{
		std::cout << "\n[TEST 5] Robotomy: multiple executions (50% behavior)" << std::endl;
		Bureaucrat chief("Chief", 1);
		RobotomyRequestForm robo("R2D2");
		chief.signForm(robo);
		chief.executeForm(robo);
		chief.executeForm(robo);
		chief.executeForm(robo);
		chief.executeForm(robo);
	}

	{
		std::cout << "\n[TEST 6] Presidential pardon success" << std::endl;
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		president.signForm(pardon);
		president.executeForm(pardon);
	}

	{
		std::cout << "\n[TEST 7] Presidential execute failure" << std::endl;
		Bureaucrat signer("Signer", 1);
		Bureaucrat lowExec("LowExec", 6);
		PresidentialPardonForm pardon("Ford Prefect");
		signer.signForm(pardon);
		lowExec.executeForm(pardon);
	}
	return (0);
}