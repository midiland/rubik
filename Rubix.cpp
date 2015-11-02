
#include <Rubix.hpp>

	Rubix::Rubix( void )
	{
		this->red = new Face(1);
		this->green = new Face(2);
		this->orange = new Face(3);
		this->blanc = new Face(4);
		this->blue = new Face(5);
		this->yello = new Face(6);

		this->FTab.push_back(boost::bind(&Rubix::action_F, this));
		this->FTab.push_back(boost::bind(&Rubix::action_R, this));
		this->FTab.push_back(boost::bind(&Rubix::action_U, this));
		this->FTab.push_back(boost::bind(&Rubix::action_B, this));
		this->FTab.push_back(boost::bind(&Rubix::action_L, this));
		this->FTab.push_back(boost::bind(&Rubix::action_D, this));
		this->FTab.push_back(boost::bind(&Rubix::action_FB, this));
		this->FTab.push_back(boost::bind(&Rubix::action_RB, this));
		this->FTab.push_back(boost::bind(&Rubix::action_UB, this));
		this->FTab.push_back(boost::bind(&Rubix::action_BB, this));
		this->FTab.push_back(boost::bind(&Rubix::action_LB, this));
		this->FTab.push_back(boost::bind(&Rubix::action_DB, this));

		return ;
	}

	void Rubix::action_U()
	{
		std::cout << "in U" << std::endl;
		this->red->rotat_left_line(1, this->green, this->orange, this->blue);
		this->yello->rotat_left_face();
		fusion_all_face();
	}


	void Rubix::action_UB()
	{

		std::cout << "in UB" << std::endl;
		this->red->rotat_right_line(1, this->green, this->orange, this->blue);
		this->yello->rotat_left_face();
		fusion_all_face();
	}
	
	void Rubix::action_D()
	{

		std::cout << "in D" << std::endl;
		this->red->rotat_right_line(3, this->green, this->orange, this->blue);
		this->blanc->rotat_right_face();
		fusion_all_face();
	}

	void Rubix::action_DB()
	{

		std::cout << "in DB" << std::endl;
		this->red->rotat_left_line(3, this->green, this->orange, this->blue);
		this->blanc->rotat_left_face();
		fusion_all_face();
	}


	void Rubix::action_R()
	{

		std::cout << "in R" << std::endl;
		this->blue->rotat_right_col(3, this->yello, this->green, this->blanc);
		this->red->rotat_right_face();
		fusion_all_face();
	}
	
	void Rubix::action_RB()
	{
		std::cout << "in RB" << std::endl;
		this->blue->rotat_left_col(3, this->yello, this->green, this->blanc);
		this->red->rotat_left_face();
		fusion_all_face();
	}

	void Rubix::action_L()
	{
		std::cout << "in L" << std::endl;
		this->blue->rotat_left_col(1, this->yello, this->green, this->blanc);
		this->orange->rotat_right_face();
		fusion_all_face();
	}


	void Rubix::action_LB()
	{
		std::cout << "in LB" << std::endl;
		this->blue->rotat_right_col(1, this->yello, this->green, this->blanc);
		this->orange->rotat_left_face();
		fusion_all_face();
	}

	void Rubix::action_F()
	{
		std::cout << "in F" << std::endl;
		this->red->rotat_left_coll(1, this->blanc, this->orange, this->yello);
		this->blue->rotat_right_face();
		fusion_all_face();
	}
	
	void Rubix::action_FB()
	{
		std::cout << "in FB" << std::endl;
		this->red->rotat_right_coll(1, this->yello, this->orange, this->blanc);
		this->blue->rotat_left_face();
		fusion_all_face();
	}

	void Rubix::action_B()
	{
		std::cout << "in B" << std::endl;
		this->red->rotat_right_coll(3, this->yello, this->orange, this->blanc);
		this->green->rotat_right_face();
		fusion_all_face();
	}
	
	void Rubix::action_BB()
	{
		std::cout << "in BB" << std::endl;
		this->red->rotat_left_coll(3, this->blanc, this->orange, this->yello);
		this->green->rotat_left_face();
		fusion_all_face();
	}


	void Rubix::run_mix(std::vector< std::vector <int> > elem)
	{
		int i;

		for (std::vector< std::vector <int> >::iterator it = elem.begin(); it != elem.end(); ++it)
		{
			i = 0;
			std::vector<int> mix = *it;
			while (i < mix[1])
			{
				this->FTab[mix[0] - 1]();
				i++;
			}
		}
	}

	void Rubix::fusion_all_face()
	{
		this->red->fusion_ligne_col();
		this->green->fusion_ligne_col();
		this->blue->fusion_ligne_col();
		this->yello->fusion_ligne_col();
		this->blanc->fusion_ligne_col();
		this->orange->fusion_ligne_col();
	}

	std::string Rubix::print_faces() const
	{
		int			i = 0;
		std::string ret;
		std::vector <std::string> fields;
		
		fields = this->yello->print_face();
		ret += "000 ";
		ret += fields[0] + "\n";
		ret += "000 ";
		ret += fields[1] + "\n";
		ret += "000 ";
		ret += fields[2] + "\n";
		while (i < 3)
		{
			fields = this->blue->print_face();
			ret += fields[i] + " ";
			fields = this->red->print_face();
			ret += fields[i] + " ";
			fields = this->green->print_face();
			ret += fields[i] + " ";
			fields = this->orange->print_face();
			ret += fields[i] + "\n";
			i++;
		}
		fields = this->blanc->print_face();
		ret += "000 ";
		ret += fields[0] + "\n";
		ret += "000 ";
		ret += fields[1] + "\n";
		ret += "000 ";
		ret += fields[2] + "\n";

		return ret;
	}

