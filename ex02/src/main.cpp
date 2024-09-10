#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "qolMacros.hpp"

int main(void)
{
	Bureaucrat b1(1);
	Bureaucrat b137(137);
	Bureaucrat b145(145);
	Bureaucrat b150(150);
	ShrubberyCreationForm f1("home");

	println(f1);
	println("");

	try
	{
		println("Trying to execute before signing...");
		b1.executeForm(f1);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	
	try
	{
		println("");
		println("Trying to sign form without suficient grade...");
		f1.beSigned(b150);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	println("");
	println("Trying to sign form with suficient grade...");
	f1.beSigned(b145);

	try
	{
		println("");
		println("Trying to execute form without suficient grade...");
		b145.executeForm(f1);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	println("");
	println("Trying to execute form with suficient grade...");
	b137.executeForm(f1);
}
