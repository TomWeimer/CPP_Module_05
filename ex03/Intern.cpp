
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Form *createRobotomyRequestForm(string target)
{
	return (new RobotomyRequestForm(target));
}
Form *createPresidentialPardonForm(string target)
{
	return (new RobotomyRequestForm(target));
}
Form *createShrubberyCreationForm(string target)
{
	return (new RobotomyRequestForm(target));
}



Intern::Intern(void) {}

Intern::Intern(const Intern& origin) {
	(void)origin;
}


Intern& Intern::operator=(const Intern& origin)
{
	(void)origin;
	cout << "Intern assignement operator called" << endl;
	return (*this);
}
Intern::~Intern(void)
{
	cout << "Intern default destructor called" << endl;
}
Form*	Intern::makeForm(string name, string target )
{
	string formNames[3];
	formNames[0] = "robotomy request";
	formNames[1] = "presidential pardon";
	formNames[2] = "shrubbery creation";

	Form* (*functionPtr[3])(string target);
	functionPtr[0] = &createRobotomyRequestForm;
	functionPtr[1] = &createPresidentialPardonForm;
	functionPtr[2] = &createShrubberyCreationForm;

	for(int i = 0; i < 3; i++)
	{
		if (name == formNames[i])	
		{
			cout << "Intern creates " << formNames[i] << " form" << endl;
			return (functionPtr[i](target));
		}
	}
	cout << "Name of the form doesn't exist!" << endl;
	return (NULL);
}