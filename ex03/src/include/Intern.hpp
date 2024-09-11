#ifndef _INTERN_HPP
#define _INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

class Intern
{
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);

	AForm* makeForm(std::string form_name, std::string target);

private:
	AForm* _makeShrubberyForm(std::string target);
	AForm* _makeRobotomyForm(std::string target);
	AForm* _makePardonForm(std::string target);
};

#endif //_INTERN_HPP
