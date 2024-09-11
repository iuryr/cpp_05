#include "RobotomyRequestForm.hpp"
#include "qolMacros.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request",
	  "Default Target", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj):
AForm(obj)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request", target, 72, 45)
{
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int draw;

	if (checkRequirements(executor) == true)
	{
		println("*Drilling Noises* BZZZZZZ");
		srand(time(NULL));
		draw = rand() % 100;
		if (draw <= 49)
		{
			println(getTarget() <<" has been robotomized.");
		}
		else 
		{
			println("Robotomy failed.");
		}
		return true;
	}
	return false;
}
