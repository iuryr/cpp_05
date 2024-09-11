#include "qolMacros.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return *this;
}

AForm* Intern::_makeShrubberyForm(std::string target)
{
	AForm* pointer = NULL;
	pointer = new ShrubberyCreationForm(target);
	return pointer;
}

AForm* Intern::_makeRobotomyForm(std::string target)
{
	AForm* pointer = NULL;
	pointer = new RobotomyRequestForm(target);
	return pointer;
}

AForm* Intern::_makePardonForm(std::string target)
{
	AForm* pointer = NULL;
	pointer = new PresidentialPardonForm(target);
	return pointer;
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	AForm* pointer = NULL;

	std::string form_names[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int i = 0;

	while (i < 4)
	{
		if (form_name == form_names[i])
		{
			break;
		}
		i++;
	}

	switch (i)
	{
		case 0:
			pointer = this->_makeShrubberyForm(target);
			println("Intern creates " << form_name << " form");
			break;
		case 1:
			pointer = this->_makeRobotomyForm(target);
			println("Intern creates " << form_name << " form");
			break;
		case 2:
			pointer = this->_makePardonForm(target);
			println("Intern creates " << form_name << " form");
			break;
		default:
			println("Intern could not create" << form_name << " form");
			break;
	}

	return pointer;
}
