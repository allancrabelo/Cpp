#ifndef		FORM_HPP
# define	FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form(); // Constructor
		Form(std::string name, const int gradeToSign, const int gradeToExecute); // Named constructor
		Form(const Form &copy); // Copy constructor
		Form &operator=(const Form &copy); // Copy Assignment constructor
		~Form(); // Destructor

	// [ Exceptions ]:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Form's grade too high!";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Form's grade too low!";
			}
	};

	// [ Getters ]:
	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	
	// [ Member Functions ]:
	void				beSigned(const Bureaucrat &Bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif