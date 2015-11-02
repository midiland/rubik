#ifndef PARSING_HPP
# define PARSING_HPP

#include <string>
#include <vector>
#include <iostream>

class Parsing
{
	public :
		Parsing(void);
		Parsing( Parsing const & src );
		~Parsing( void );
		void run_lex(std::string str);
		std::string to_string();
		std::vector< std::vector<int> > get_elem();

		class LexingException : std::exception {
			public:
				virtual const char* what() const throw();
		};

		class ClassException : std::exception {
			public:
				virtual const char* what() const throw();
		};


	private :
		int check_letre(char c);
		int check_number(char c);
		void check_str( std::string str );
		void add_elem(int action, int nb);
		std::vector< std::vector<int> > elem;
		std::string error;
};



#endif
