#include <parsing.hpp>

Parsing::Parsing()
{
}

void Parsing::run_lex(std::string str)
{
	try
	{
		this->check_str(str);
	}
	catch (LexingException & e)
	{
		std::cout << e.what() << this->error << std::endl;
		throw ClassException();
	}
}

void Parsing::add_elem(int action, int nb)
{
	std::vector<int> add;

	if (nb == 3)
	{
		add.push_back((action + 6));
		add.push_back(1);
	}
	else
	{
		add.push_back(action);
		add.push_back(nb);
	}
	this->elem.push_back(add);
}

int Parsing::check_letre(char c)
{
	if (c == 'F')
		return 1;
	if (c == 'R')
		return 2;
	if (c == 'U')
		return 3;
	if (c == 'B')
		return 4;
	if (c == 'L')
		return 5;
	if (c == 'D')
		return 6;
	return 0;
}

int Parsing::check_number(char c)
{
	if (c == '1')
		return 1;
	if (c == '2')
		return 2;
	if (c == 39)
		return 3;
	return 0;
}

std::string Parsing::to_string()
{
	std::string ret;

	for (std::vector< std::vector<int> >::iterator it = this->elem.begin(); it != this->elem.end(); ++it)
	{
		std::vector<int> tmp = *it;
		ret += "action = ";
		for (std::vector<int>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2)
		{
			ret += *it2 + 48;
			ret += " ";
		}
		ret += "\n";
	}
	return ret;
}

void Parsing::check_str(std::string str)
{
	int i = 0;
	int y = 1;
	int ic = 0;
	int in = 0;
	char c = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{

		std::cout << *it  << "i = " << i << std::endl;
		if (i == 0)
		{
			if ((ic = check_letre(*it)) < 1)
			{
				this->error = "char = "; 
				this->error += str[y - 1]; 
				this->error += "number = "; 
				this->error += y + 48;
				throw LexingException();
			}
		}
		else if (i == 1)
		{
			if ((in = check_number(*it)) >= 1)
				add_elem(ic, in);
			else if (*it == ' ')
			{
				i = -1;
				add_elem(ic, 1);
			}
			else 
			{
				this->error = "char = ";
				this->error += str[y - 1];
				this->error += "number = "; 
				this->error += y + 48;
				throw LexingException();
			}
		}
		else if (i == 2)
			i = -1;
		i++;
		y++;
	}
	if (i == 1)
	{
		add_elem(ic, 1);
	}
}


std::vector< std::vector<int> > Parsing::get_elem()
{
	return this->elem;
}

const char* Parsing::LexingException::what() const throw()
{
	return ("Error lexing : ");
}

const char* Parsing::ClassException::what() const throw()
{
	return ("Error create class");
}
