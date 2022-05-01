#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
	private:
	string target_;
	RobotomyRequestForm(void);
	public:
	RobotomyRequestForm(string target);
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm(void);
	void execute(Bureaucrat const & executor)const;

	string getTarget(void)const;
};
# endif