#ifndef _FORM_HPP_
#define _FORM_HPP_

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Form
{
public:
	Form(void);
	~Form(void);
	Form(const Form& obj);
	Form& operator=(const Form& obj);

	Form(std::string name, unsigned int signGrade, unsigned int execGrade);

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

#endif // _FORM_HPP
