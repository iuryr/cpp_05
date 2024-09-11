#ifndef _PRESIDENTIAL_PARDON_FORM_HPP_
#define _PRESIDENTIAL_PARDON_FORM_HPP_

#include <iostream>

#include "AForm.hpp"


class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

	PresidentialPardonForm(std::string target);

	bool execute(Bureaucrat const & executor) const;
};

#endif //_PRESIDENTIAL_PARDON_FORM_HPP_
