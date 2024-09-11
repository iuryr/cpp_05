#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
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

	println("");
	println("Robotomy Request tests");
	Bureaucrat b45(45);
	Bureaucrat b72(72);
	RobotomyRequestForm f2("Bender");

	println(f2);
	println("");

	try
	{
		println("Trying to execute before signing...");
		b1.executeForm(f2);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	
	try
	{
		println("");
		println("Trying to sign form without suficient grade...");
		f2.beSigned(b150);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	println("");
	println("Trying to sign form with suficient grade...");
	f2.beSigned(b72);

	try
	{
		println("");
		println("Trying to execute form without suficient grade...");
		b72.executeForm(f2);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	println("");
	println("Trying to execute form with suficient grade...");
	b45.executeForm(f2);

	println("");
	println("Presidential Pardon tests");
	Bureaucrat b25(25);
	Bureaucrat b5(5);
	PresidentialPardonForm f3("Iury");

	println(f3);
	println("");

	try
	{
		println("Trying to execute before signing...");
		b1.executeForm(f3);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	
	try
	{
		println("");
		println("Trying to sign form without suficient grade...");
		f3.beSigned(b150);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	println("");
	println("Trying to sign form with suficient grade...");
	f3.beSigned(b25);

	try
	{
		println("");
		println("Trying to execute form without suficient grade...");
		b25.executeForm(f3);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	println("");
	println("Trying to execute form with suficient grade...");
	b5.executeForm(f3);
}
