
#ifndef RUBIX_HPP
# define RUBIX_HPP

#include "Face.hpp"
#include <boost/function.hpp>
#include <boost/bind.hpp>

class Rubix
{
	public:
		Rubix();
		Rubix( Rubix const & src );
		~Rubix( void );

		int check_face(Face f);

		std::string print_faces() const;

		void action_U();
		void action_UB();
		void action_D();
		void action_DB();
		void action_RB();
		void action_R();
		void action_L();
		void action_LB();
		void action_F();
		void action_FB();
		void action_B();
		void action_BB();
		void run_mix(std::vector< std::vector <int> > elem);


		/* GETTER */
		Face get_red ();
		Face get_green ();
		Face get_blue ();
		Face get_yello ();
		Face get_blanc ();
		Face get_orange ();

	private:
		void fusion_all_face();
		Face *red;
		Face *green;
		Face *blue;
		Face *yello;
		Face *blanc;
		Face *orange;
		std::vector < boost::function<void()> > FTab;
};


#endif
