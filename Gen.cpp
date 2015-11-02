#include <gen.hpp>

Gen::Gen()
{
	this->rubix = new Rubix();
	this->parsing = new Parsing();
}

void Gen::run_mix(std::string str)
{
	try
	{
		this->parsing->run_lex(str);
		std::cout << this->parsing->to_string() << std::endl;
		this->rubix->run_mix(this->parsing->get_elem());
	}
	catch (Parsing::ClassException & e)
	{
		std::cout << e.what() << std::endl;
	}
}

Rubix *Gen::get_rubix()
{
	return this->rubix;
}

const char* Gen::GenMixException::what() const throw()
{
	return ("Error in Gen Mix methode class");
}
