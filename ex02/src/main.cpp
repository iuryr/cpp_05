#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "qolMacros.hpp"

int main(void)
{
	Bureaucrat b1(1);
	Bureaucrat b2("Mendonça", 2);
	Form f1;

	println("Form information:");
	println(f1);
	println("");

	println("Bureaucrats information:");
	println(b1);
	println(b2);
	println("");

	println("Let the lesser bereaucrat try and sign the form...");
	try 
	{
		f1.beSigned(b2);
	}
	catch (std::exception& e)
	{
		e.what();
	}
	println("");

	println("Now let's call the pros...");
	f1.beSigned(b1);
	println(f1);
	println("");

	println("Let the pro try to sign an already signed form...");
	f1.beSigned(b1);
	println(f1);

	println("");
	println("Testing exception throwing for malformed forms (get it? huh?)");
	try 
	{
		Form f2("Bad Form", 1000, 1);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	try 
	{
		Form f2("Bad Form", 1, 1000);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	try 
	{
		Form f2("Bad Form", 0, 1);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	try 
	{
		Form f2("Bad Form", 1, 0);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	try 
	{
		Form f2("Bad Form", 0, 1000);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}

	try 
	{
		Form f2("Bad Form", 1000, 0);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
}
