
#include <Rubix.hpp>
#include <parsing.hpp>
#include <gen.hpp>


int			main(int argc, char *argv[])
{
	Rubix *myRubix = new Rubix();
	Parsing *myParsing; 
	Gen *myGen; 
	int i = 0;
	if (argc == 2)
	{
		std::string str;
		while (argv[1][i])
		{
			str.push_back(argv[1][i]);
			i++;
		}
		myGen = new Gen();
		myGen->run_mix(str);
	/*		myParsing = new Parsing();
			try
			{
				myParsing->run_lex(str);
			}
			catch (Parsing::ClassException & e)
			{
				std::cout << e.what() << std::endl;
			}
			std::cout << myParsing->to_string();*/
	}
	else
	{
		std::cout << "Error" << std::endl;
	}


//	myRubix->action_R();
//	myRubix->action_U();

//	myRubix->action_U();
//	myRubix->action_UB();
//	myRubix->action_D();
//	myRubix->action_DB();
//	myRubix->action_R();
//	myRubix->action_RB();
//	myRubix->action_L();
//	myRubix->action_LB();
//	myRubix->action_F();
//	myRubix->action_FB();
//	myRubix->action_B();
//	myRubix->action_BB();


	std::cout << myGen->get_rubix()->print_faces();

	return (0);
}
