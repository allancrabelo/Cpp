#ifndef		AFORM_HPP
# define	AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	protected:
		virtual void		executeAction() const = 0; // Abstract
	public:
		AForm(); // Constructor
		AForm(std::string name, const int gradeToSign, const int gradeToExecute); // Named constructor
		AForm(const AForm &copy); // Copy constructor
		AForm &operator=(const AForm &copy); // Copy Assignment constructor
		virtual ~AForm(); // Destructor

	// [ Exceptions ]:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "AForm's grade too high!";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "AForm's grade too low!";
			}
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "AForm is not signed!";
			}
	};

	// [ Getters ]:
	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	
	// [ Member Functions ]:
	void				beSigned(const Bureaucrat &Bureaucrat);
	void				execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif