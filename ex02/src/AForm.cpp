#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("Default AForm"), _target("Default Target"), _isSigned(false),_signGrade(1), _execGrade(1)
{
}

AForm::~AForm(void)
{
}

AForm::AForm(const AForm& obj): _name(obj.getName()),_target(obj.getTarget()), _isSigned(obj.isSigned()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		this->_isSigned = obj.isSigned();
	}
	return *this;
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade):
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(std::string name, std::string target, unsigned int signGrade, unsigned int execGrade):
_name(name), _target(target), _isSigned(false), _signGrade(signGrade),
_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

void AForm::beSigned(Bureaucrat& obj)
{
	obj.signForm(*this);
	
	if (this->getSignGrade() < obj.getGrade())
	{
		throw AForm::GradeTooHighException();
		return;
	}
	else
	{
		this->_isSigned = true;
	}
}

std::string AForm::getName(void) const
{
	return this->_name;
}

std::string AForm::getTarget(void) const
{
	return this->_target;
}


bool AForm::isSigned(void) const
{
	return this->_isSigned;
}

unsigned int AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

unsigned int AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "Form Grade is too high.";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "Form Grade is too low.";
}

const char* AForm::UnsignedFormException::what(void) const throw()
{
	return "Form is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
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

bool AForm::checkRequirements(const Bureaucrat& executor) const
{
	if (this->isSigned() == false)
	{
		throw UnsignedFormException();
	}
	if (this->getExecGrade() < executor.getGrade())
	{
		throw GradeTooHighException();
	}
	return true;
}
