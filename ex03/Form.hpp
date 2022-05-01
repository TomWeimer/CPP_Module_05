#ifndef FORM_H
# define FORM_H
#include <iostream>
using namespace std;
#include "Bureaucrat.hpp"

class Form
{
	private:
	const string	name_;
	bool			isSigned_;// = false;
	int				gradeToSign_;
	int				gradeToExecute_;
	Form();

	public:
	Form(string name, int gradeToSign, int gradeToExecute);
	Form(const Form&);
	Form& operator=(const Form&);
	virtual ~Form();

	string		getName(void)const;
	int			getGradeToSign(void)const;
	int			getGradeToExecute(void)const;
	bool 		getIsSigned(void)const;
	void		beSigned(const Bureaucrat&);
	virtual void execute(Bureaucrat const & executor)const = 0;
	class GradeTooHighException;
	class GradeTooLowException;
};
ostream &operator<<(ostream &out, Form const &form);
ostream &operator<<(ostream &out, Bureaucrat const &bureaucrat);

class Form::GradeTooHighException : public exception
{
	public:
		virtual const char* what(void) const throw()
		{
			return ("The grade needed to sign/or to execute the form is too high, it doesn't exist!");
		}
};

class  Form::GradeTooLowException : public exception
{
	public:
		virtual const char* what(void) const throw()
		{
			return ("The grade of the bureaucrat isn't high enough to execute/sign the form!");
		}
};
# endif