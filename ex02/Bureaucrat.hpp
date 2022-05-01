#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <iostream>
#include <fstream> 
#include <stdlib.h>
#include <time.h>    
using namespace std;
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

#include "Form.h"

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
	void	signForm(class Form& source);

	Bureaucrat&	incrementGrade(void);
	Bureaucrat&	decrementGrade(void);

	void executeForm(Form const & form);

	

	class GradeTooHighException;
	class GradeTooLowException;
};



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