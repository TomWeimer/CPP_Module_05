#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
#include "Form.hpp"
class PresidentialPardonForm : public Form
{
	private:
	string target_;
	PresidentialPardonForm(void);
	public:
	PresidentialPardonForm(string target);
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	~PresidentialPardonForm(void);
	void execute(Bureaucrat const & executor)const;

	string getTarget(void)const;
};
# endif