#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class AForm
{
public:
	AForm(void);
	virtual ~AForm(void);
	AForm(const AForm& obj);
	AForm& operator=(const AForm& obj);

	AForm(std::string name, unsigned int signGrade, unsigned int execGrade);
	AForm(std::string name, std::string target, unsigned int signGrade, unsigned int execGrade);

	void beSigned(Bureaucrat& obj);
	bool checkRequirements(const Bureaucrat& executor) const;
	virtual bool execute(Bureaucrat const & executor) const = 0;

	std::string getName(void) const;
	std::string getTarget(void) const;
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

	class UnsignedFormException: public std::exception
	{
	public:
		const char* what(void) const throw();
	};

private:
	const std::string _name;
	const std::string _target;
	bool _isSigned;
	const unsigned int _signGrade;
	const unsigned int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif // _AFORM_HPP
