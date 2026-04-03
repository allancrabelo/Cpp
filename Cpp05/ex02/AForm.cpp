#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default AForm constructor called." << std::endl;
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Named AForm Constructor called." << std::endl;
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Copy AForm constructor called." << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "Copy Assignment AForm constructor called." << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called." << std::endl;
}

const std::string	AForm::getName() const
{
	return (_name);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

int					AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int					AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm '" << f.getName() << "'"
		<< ", signed: " << (f.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}