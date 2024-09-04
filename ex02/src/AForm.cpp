#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Default Form"), _isSigned(false),_signGrade(1),
	_execGrade(1)
{
}

Form::~Form(void)
{
}

Form::Form(const Form& obj): _name(obj.getName()), _isSigned(obj.isSigned()),
	_signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		this->_isSigned = obj.isSigned();
	}
	return *this;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade):
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

void Form::beSigned(Bureaucrat& obj)
{
	obj.signForm(*this);
	
	if (this->getSignGrade() < obj.getGrade())
	{
		throw Form::GradeTooLowException();
		return;
	}
	else
	{
		this->_isSigned = true;
	}
}

std::string Form::getName(void) const
{
	return this->_name;
}


bool Form::isSigned(void) const
{
	return this->_isSigned;
}

unsigned int Form::getSignGrade(void) const
{
	return this->_signGrade;
}

unsigned int Form::getExecGrade(void) const
{
	return this->_execGrade;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form Grade is too high.";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "Form Name: " << obj.getName() << ". Sign Grade: " <<
	obj.getSignGrade() << ". Exec Grade: " << obj.getExecGrade();

	if (obj.isSigned() == false)
	{
		os << ". Is it signed? No.";
	}
	else 
	{
		os << ". Is it signed? Yes.";
	}

	return os;
}


