#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "qolMacros.hpp"

#include <exception>

Bureaucrat::Bureaucrat(void): _name("Lineu"), _grade(150)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): _name(obj._name), _grade(obj._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		this->_grade = obj.getGrade();
	}
	
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(int grade): _name("Lineu")
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_grade = grade;
	}
}

void Bureaucrat::signForm(AForm& obj)
{
	if (this->getGrade() <= obj.getSignGrade())
	{
		if (obj.isSigned() == true)
		{
			println(this->getName() << " could not sign form " << obj.getName()
		   << " because it is already signed.");
			return;
		}

		println(this->getName() << " signed form " << obj.getName());
	}
	else 
	{
		println(this->getName() << " could not sign form " << obj.getName()
		  <<" because bureaucrat level is too low.");
	}
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else 
	{
		this->_grade--;
		return;
	}
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else 
	{
		this->_grade++;
		return;
	}
}

unsigned int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat Max Grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat Min Grade is 150.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
