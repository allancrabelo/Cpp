#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), _target("default")
{
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyForm", 145, 137), _target(target)
{
	std::cout << "Target ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	std::cout << "Copy Assignment ShrubberyCreationForm constructor called." << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "         A               A               A\n";
	file << "        d$b             d$b             d$b\n";
	file << "      .d\\$$b.         .d\\$$b.         .d\\$$b.\n";
	file << "    .d$i$$\\$$b.     .d$i$$\\$$b.     .d$i$$\\$$b.\n";
	file << "       d$$@b           d$$@b           d$$@b\n";
	file << "      d\\$$$ib         d\\$$$ib         d\\$$$ib\n";
	file << "    .d$$$\\$$$b       .d$$$\\$$$b       .d$$$\\$$$b\n";
	file << "  .d$$@$$$$\\$$ib.  .d$$@$$$$\\$$ib.  .d$$@$$$$\\$$ib.\n";
	file << "      d$$i$$b         d$$i$$b         d$$i$$b\n";
	file << "     d\\$$$$@$b       d\\$$$$@$b       d\\$$$$@$b\n";
	file << "  .d$@$$\\$$$$$@b.  .d$@$$\\$$$$$@b.  .d$@$$\\$$$$$@b.\n";
	file << ".d$$$$i$$$\\$$$$$$b..d$$$$i$$$\\$$$$$$b..d$$$$i$$$\\$$$$$$b.\n";
	file << "          ###             ###             ###\n";
	file << "          ###             ###             ###\n";
	file << "          ###             ###             ###\n";
	file.close();
}