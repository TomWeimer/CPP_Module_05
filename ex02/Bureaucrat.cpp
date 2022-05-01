
#include "Form.hpp"
bool checkCondition(Form const & form, int bureaucratGrade)
{
	if (form.getGradeToExecute() < bureaucratGrade)
	{
		return (false);
	}
	return (true);
}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(string name, int grade) : name_(name), grade_(grade)
{
	cout << "Bureaucrat default constructor called" << endl;
	if (grade_ < HIGHEST_GRADE)
		throw  GradeTooHighException();
	else if (grade_ > LOWEST_GRADE )
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name_(origin.getName()), grade_(origin.getGrade())
{
	cout << "Bureaucrat copy constructor called" << endl;
	if (grade_ < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade_ > LOWEST_GRADE )
		throw GradeTooLowException();
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin)
{
	cout << "Bureaucrat assignement operator called" << endl;
	if (this == &origin)
		return (*this);
	this->grade_ = origin.getGrade();
	return (*this);
}
Bureaucrat::~Bureaucrat(void)
{
	cout << "Bureaucrat default destructor called" << endl;
}

string Bureaucrat::getName(void)const
{
	return (this->name_);
}

int Bureaucrat::getGrade(void)const
{
	return(this->grade_);
}

Bureaucrat& Bureaucrat::incrementGrade(void)
{
	cout << "Bureaucrat incrementGrade called" << endl;
	this->grade_ -= 1;
	if (grade_ < HIGHEST_GRADE)
		throw GradeTooHighException();
	return (*this);
}

Bureaucrat& Bureaucrat::decrementGrade(void)
{
	cout << "Bureaucrat decrementGrade called" << endl;
	this->grade_ += 1;
	if (grade_ > LOWEST_GRADE)
		throw GradeTooLowException();
	return (*this);
}
void Bureaucrat::signForm(Form &source)
{
	source.beSigned(*this);
	cout << name_ << " signed " << source.getName() << endl;
}

ostream &operator<<(ostream &out, Bureaucrat const &bureaucrat)
{
	out << "name: " << bureaucrat.getName() << "| grade: " << bureaucrat.getGrade() << endl;
	return (out);
}

void Bureaucrat::executeForm(Form const & form)
{
	if (checkCondition(form, this->getGrade()))
	{
		form.execute(*this);
		cout << this->name_ << " executeed " << form.getName() << endl;
	}
	else
	{
		cout << this->name_ << " couldn't executeed " << form.getName()<< "because his grade was not enough." << endl;
		throw GradeTooLowException();
	
	}
}