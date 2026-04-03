#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

// Includes:
# include <iostream>
# include <string>

class		Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;// [1 - Highest ~ 150 - Lowest]
	public:
		Bureaucrat(); // Default Constructor
		Bureaucrat(const std::string name, int grade); // Named Constructor
		Bureaucrat(const Bureaucrat &copy); // Copy Constructor
		Bureaucrat &operator=(const Bureaucrat &copy); // Copy Assignment Constructor
		~Bureaucrat(); // Destructor

	// [ Expeptions ]:
	class	GradeTooHighException : public	std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too high!";
			}	
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual	const char* what() const throw()
			{
				return "Grade is too low!";
			}	
	};

	// [ Getters ]:
	const std::string	getName() const;
	int					getGrade() const;

	// [ Mutators ]:
	void				increment();
	void				decrement();
	
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
