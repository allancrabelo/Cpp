#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default Form constructor called." << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Named Form Constructor called." << std::endl;
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Copy Form constructor called." << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Copy Assignment Form constructor called." << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor Form called." << std::endl;
}

const std::string	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

int					Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int					Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form '" << f.getName() << "'"
		<< ", signed: " << (f.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}