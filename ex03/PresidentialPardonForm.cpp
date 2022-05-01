#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string target) 
: Form("PresidentialPardonForm", 25, 5)
{
	cout << "PresidentialPardonFor default constructor called!" << endl;
	this->target_ = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin) 
: Form("PresidentialPardonForm", 25, 5)
{
	cout << "PresidentialPardonForm copy constructor called!" << endl;
	this->target_ = origin.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin)
{
	cout << "PresidentialPardonForm assignement operator called" << endl;
	if (this == &origin)
		return (*this);
	this->target_ = origin.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	cout << "PresidentialPardonForm destructor called!" << endl;
}

string PresidentialPardonForm::getTarget(void)const
{
	return (this->target_);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
	(void)executor;
	cout << target_ << " has been forgiven by Zaphod Beeblebrox." << endl;
}