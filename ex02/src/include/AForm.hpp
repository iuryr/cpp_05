#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class AForm
{
public:
	AForm(void);
	~AForm(void);
	AForm(const Form& obj);
	AForm& operator=(const Form& obj);

	AForm(std::string name, unsigned int signGrade, unsigned int execGrade);

	virtual void execute(Bureaucrat& obj) = 0;
	void beSigned(Bureaucrat& obj);

	std::string getName(void) const;
	bool isSigned(void) const;
	unsigned int getSignGrade(void) const;
	unsigned int getExecGrade(void) const;

	class GradeTooHighException: public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		const char* what(void) const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const unsigned int _signGrade;
	const unsigned int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif // _AFORM_HPP
