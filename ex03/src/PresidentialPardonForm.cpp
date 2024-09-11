#include "PresidentialPardonForm.hpp"
#include "qolMacros.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon",
	  "Default Target", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj):
AForm(obj)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", target, 25, 5)
{
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (checkRequirements(executor) == true)
	{
		println(getTarget() << " has been pardoned by Zaphod BeebleBrox");

		return true;
	}
	return false;
}
