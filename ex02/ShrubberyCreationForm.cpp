#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) 
: Form("ShrubberyCreationForm", 25, 5)
{
	cout << "ShrubberyCreationForm default constructor called!" << endl;
	this->target_ = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin) 
: Form("ShrubberyCreationForm", 25, 5)
{
	cout << "ShrubberyCreationForm copy constructor called!" << endl;
	this->target_ = origin.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin)
{
	cout << "ShrubberyCreationForm assignement operator called" << endl;
	if (this == &origin)
		return (*this);
	this->target_ = origin.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	cout << "ShrubberyCreationForm destructor called!" << endl;
}

string ShrubberyCreationForm::getTarget(void)const
{
	return (this->target_);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	(void)executor;
	string namefile = target_;
	namefile.append("_shrubbery");

	string tree =	"     ccee88oo\n";
	tree +=			"  C8O8O8Q8PoOb o8oo\n";
	tree +=			" dOB69QO8PdUOpugoO9bD\n";
	tree +=			"CgggbU8OU qOp qOdoUOdcb\n";
	tree +=			"    6OuU  /p u gcoUodpP\n";
	tree +=			"      \\\\\\//  /douUP\n";
	tree +=			"        \\\\\\////\n";
	tree +=			"         |||/\\\n";
	tree +=			"         |||\\/\n";
	tree +=			"         |||||\n";
	tree +=			"   .....//||||\\....\n";
	tree +=			"   David Moore\n";

	ofstream outFile(namefile, ios::out);
	outFile << tree << endl;
	outFile.close();
}