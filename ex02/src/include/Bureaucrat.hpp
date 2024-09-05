#ifndef _BUREAUCRAT_HPP
#define _BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& obj);

	Bureaucrat(std::string name, int grade);
	Bureaucrat(int grade);

	void signForm(AForm& obj);
	void incrementGrade(void);
	void decrementGrade(void);

	std::string getName(void) const;
	unsigned int getGrade(void) const;

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
	std::string const _name;
	unsigned int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif //_BUREAUCRAT_HPP_
