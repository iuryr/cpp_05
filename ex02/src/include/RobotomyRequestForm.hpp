#ifndef _ROBOTOMY_REQUEST_FORM_HPP_
#define _ROBOTOMY_REQUEST_FORM_HPP_

#include <iostream>

#include "AForm.hpp"


class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

	RobotomyRequestForm(std::string target);

	bool execute(Bureaucrat const & executor) const;
};

#endif //_ROBOTOMY_REQUEST_FORM_HPP_
