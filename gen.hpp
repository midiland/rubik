#ifndef GEN_HPP
# define GEN_HPP

#include <Rubix.hpp>
#include <parsing.hpp>

class Gen
{
	public:
		Gen( void );
		~Gen( void );
		void run_mix(std::string str);
		void run_resolve( void );
		Rubix *get_rubix();

		class GenMixException : std::exception {
			public:
				virtual const char* what() const throw();
		};


	private:
		Rubix *rubix;
		Parsing *parsing;


};

#endif
