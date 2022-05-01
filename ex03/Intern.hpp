#ifndef Intern_H
# define Intern_H

#include "Form.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	Form*	makeForm( std::string name, std::string target );
	class UnknownForm;
};

class Intern::UnknownForm : public exception
{
	public:
		virtual const char* what(void) const throw()
		{
			return ("The name of the form doesn't exist!");
		}
};



#endif