#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"
class ShrubberyCreationForm : public Form
{
	private:
	string target_;
	ShrubberyCreationForm(void);
	public:
	ShrubberyCreationForm(string target);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	~ShrubberyCreationForm(void);
	void execute(Bureaucrat const & executor)const;

	string getTarget(void)const;
};
# endif