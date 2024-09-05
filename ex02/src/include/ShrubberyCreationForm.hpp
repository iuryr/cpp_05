#ifndef _SHRUBBERY_CREATION_FORM_HPP_
#define _SHRUBBERY_CREATION_FORM_HPP_

#include <iostream>

#include "AForm.hpp"


class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

	ShrubberyCreationForm(std::string target);
};

#endif //_SHRUBBERY_CREATION_FORM_HPP_
