#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called." << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern Copy Constructor called." << std::endl;
	(void)copy; // That Will not result without (void)
}

Intern	&Intern::operator=(const Intern &copy)
{
	std::cout << "Intern Copy Assignment Constructor called." << std::endl;
	(void)copy; // That Will not result without (void)
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called." << std::endl;
}

AForm	*Intern::createShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	const std::string	map[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*creators[3])(const std::string &target) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (name == map[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	std::cout << "Intern couldn't create form \"" << name
		<< "\": unknown form name." << std::endl;
	throw InternException();
}
