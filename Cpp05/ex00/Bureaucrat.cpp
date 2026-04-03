#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade()
{
	std::cout << "Default constructor called."  << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Named constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Copy assignment constuctor called." << std::endl;
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called." << std::endl;
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return(_grade);
}

void	Bureaucrat::increment()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
