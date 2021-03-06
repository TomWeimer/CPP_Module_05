

#include <iostream>
#include <string>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void _test_intern(std::string const& name, std::string const& target) {
    std::cout << "< " << name << " >" << std::endl;

    Intern someRandomIntern;
    Form* rrf;
    Bureaucrat bure("Akira", 1);

    rrf = someRandomIntern.makeForm(name, target);

    if (rrf) {
        std::cout << bure;
        bure.signForm(*rrf);
        std::cout << *rrf;
        bure.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
}

int main() {
	std::srand(std::time(NULL));
    std::cout << "<< SHURUBBERY TESTS >>" << std::endl;
    _test_intern("shrubbery creation", "Bender");
    _test_intern("robotomy request", "Bender");
    _test_intern("presidential pardon", "Bender");
    _test_intern("\'nothing form\'", "Bender");
    return 0;
}