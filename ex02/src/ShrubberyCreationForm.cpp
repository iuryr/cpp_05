#include "ShrubberyCreationForm.hpp"
#include "qolMacros.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Creation",
	  "Default Target", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj):
AForm(obj)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation", target, 145, 137)
{
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (checkRequirements(executor) == true)
	{
		std::string file_name = getTarget() + "_shrubbery";
		std::ofstream output_file(file_name.c_str(), std::ios_base::trunc);

		if (output_file.is_open() == false)
		{
			println("Error opening output file.");
			return false;
		}

		output_file << ""
"                            	        ,@@@@@@@,\n"
"                               ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
"                            ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
"                           ,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n"
"                           %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'\n"
"                           %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"                           `&%\\ ` /%&'    |.|        \\ '|8\'\n"
"                               |o|        | |         | |\n"
"                               |.|        | |         | |\n";

		output_file.close();
		return true;
	}
	return false;
}
