#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <iostream>
using namespace std;
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
	private:
	string	name_;
	int		grade_;
	Bureaucrat();
	public:
	Bureaucrat(string name, int level);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat();

	string		getName(void)const;
	int			getGrade(void)const;

	Bureaucrat&	incrementGrade(void);
	Bureaucrat&	decrementGrade(void);

	class GradeTooHighException;
	class GradeTooLowException;
};

ostream &operator<<(ostream &out, Bureaucrat const &bureaucrat);

class Bureaucrat::GradeTooHighException : public exception
{
	public:
		virtual const char* what(void) const throw()
		{
			return ("The grade of the bureaucrat is too high, it doesn't exist!");
		}
};

class  Bureaucrat::GradeTooLowException : public exception
{
	public:
		virtual const char* what(void) const throw()
		{
			return ("The grade of the bureaucrat is too low, it doesn't exist!");
		}
};

#endif