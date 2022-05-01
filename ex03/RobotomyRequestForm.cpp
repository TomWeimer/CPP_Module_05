#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(string target) 
: Form("RobotomyRequestForm", 25, 5)
{
	cout << "RobotomyRequestForm default constructor called!" << endl;
	this->target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin) 
: Form("RobotomyRequestForm", 25, 5)
{
	cout << "RobotomyRequestForm copy constructor called!" << endl;
	this->target_ = origin.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin)
{
	cout << "RobotomyRequestForm assignement operator called" << endl;
	if (this == &origin)
		return (*this);
	this->target_ = origin.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	cout << "RobotomyRequestForm destructor called!" << endl;
}

string RobotomyRequestForm::getTarget(void)const
{
	return (this->target_);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{

	
	cout << "bzzzzzz bzzzzzz" << endl;
	int probabilty = rand();
	if (probabilty % 2)
	{
		cout << target_<< "has been robotomized." << endl;
	}
	else
		cout << "The robotomization of " << target_ << "has failed." << endl;
	(void)executor;
}