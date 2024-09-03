#include "Bureaucrat.hpp"
#include "qolMacros.hpp"

int main(void)
{
	println("Bureaucrat b1;");
	Bureaucrat b1;

	println("Bureaucrat b2(b1);");
	Bureaucrat b2(b1);

	println("Bureaucrat b3 = b1;");
	Bureaucrat b3 = b1;
	println("");

	println("" << b3);
	println("");
	println("Incrementing b3 grade by 1...");
	b3.incrementGrade();
	println("" << b3);
	println("");
	println("Decrementing b3 grade by 1...");
	b3.decrementGrade();
	println("" << b3);
	println("");

	println("Try-Catch: Decrementing grade out of bound:");
	try
	{
		b3.decrementGrade();
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

	println("Try-Catch: Incrementing grade out of bound:");
	Bureaucrat b4(1);
	try
	{
		b4.incrementGrade();
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

	println("Try-Catch: Construction out of lower bound");
	try
	{
		Bureaucrat b5(151);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");

	println("Try-Catch: Construction out of upper bound");
	try
	{
		Bureaucrat b5(-50);
	}
	catch (std::exception& e)
	{
		println(e.what());
	}
	println("");
}
