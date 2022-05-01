#include "Form.hpp"

Form::Form(void) {}

Form::Form(string name, int gradeToSign, int gradeToExecute) : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	cout << "Form default constructor called" << endl;
	this->isSigned_ = false;
	if (gradeToSign_  < HIGHEST_GRADE || gradeToExecute_ < HIGHEST_GRADE)
		throw  GradeTooHighException();
	else if (gradeToSign_  > LOWEST_GRADE || gradeToExecute_ > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& origin) : name_(origin.getName()), gradeToSign_(origin.getGradeToSign()), gradeToExecute_(origin.getGradeToExecute())
{
	cout << "Form copy constructor called" << endl;
	this->isSigned_ = origin.getIsSigned();
	if (gradeToSign_  < HIGHEST_GRADE || gradeToExecute_ < HIGHEST_GRADE)
		throw  GradeTooHighException();
	else if (gradeToSign_  > LOWEST_GRADE || gradeToExecute_ > LOWEST_GRADE)
		throw GradeTooLowException();
	
}

Form& Form::operator=(const Form& origin)
{
	cout << "Form assignement operator called" << endl;
	if (this == &origin)
		return (*this);
	this->gradeToSign_ = origin.getGradeToSign();
	this->gradeToExecute_ = origin.getGradeToExecute();
	return (*this);
}
Form::~Form(void)
{
	cout << "Form default destructor called" << endl;
}

string Form::getName(void)const
{
	return (this->name_);
}

int Form::getGradeToExecute(void)const
{
	return(this->gradeToExecute_);
}
int Form::getGradeToSign(void)const
{
	return(this->gradeToSign_);
}
bool Form::getIsSigned(void)const
{
	return(this->isSigned_);
}

ostream &operator<<(ostream &out, Form const &Form)
{
	out << "name: " << Form.getName() << "| gradeToSign: " << Form.getGradeToSign() << " gradeToExecute: " << Form.getGradeToExecute() << endl;
	return (out);
}


void Form::beSigned(const Bureaucrat& worker)
{
	int workerGrade;
	workerGrade = worker.getGrade();
	if (workerGrade > this->getGradeToSign())
	{
		cout << this->name_ << " couldn't sign " << this->name_ << " because " << "his rank was too low!" << endl;
		throw GradeTooLowException();
	}
	this->isSigned_ = true;
}
