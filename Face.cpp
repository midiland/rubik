# include <Rubix.hpp>
# include <string>
#include <iostream>
#include <sstream>

	Face::Face (int c)
	{
		this->line1.push_back(c);
		this->line1.push_back(c);
		this->line1.push_back(c);
		this->line2.push_back(c);
		this->line2.push_back(c);
		this->line2.push_back(c);
		this->line3.push_back(c);
		this->line3.push_back(c);
		this->line3.push_back(c);
		this->col1.push_back(c);
		this->col1.push_back(c);
		this->col1.push_back(c);
		this->col2.push_back(c);
		this->col2.push_back(c);
		this->col2.push_back(c);
		this->col3.push_back(c);
		this->col3.push_back(c);
		this->col3.push_back(c);
		return ;
	}

	std::string Face::get_line(std::vector<int> l) const
	{ 
		std::string s;
		std::ostringstream convert;

		for (std::vector<int>::iterator it=l.begin(); it != l.end(); ++it)
		{
			convert << *it;
		}
		s += convert.str();
		return s;
	}

	std::vector<std::string>  Face::print_face() const
	{
		std::vector <std::string> fields;

		fields.push_back(get_line(this->line1));
		fields.push_back(get_line(this->line2));
		fields.push_back(get_line(this->line3));

		return fields;
	}

	void Face::rotat_left_line(int line, Face *obj1, Face *obj2, Face *obj3)
	{
		std::vector<int> sav;

		if (line == 1)
		{
			sav = this->line1;
			this->set_line1(obj1->get_line1());
			obj1->set_line1(obj2->get_line1());
			obj2->set_line1(obj3->get_line1());
			obj3->set_line1(sav);
		}
		else if (line == 3)
		{
			sav = this->line3;
			this->set_line3(obj1->get_line3());
			obj1->set_line3(obj2->get_line3());
			obj2->set_line3(obj3->get_line3());
			obj3->set_line3(sav);
		}
	}

	void Face::rotat_right_line(int line, Face *obj1, Face *obj2, Face *obj3)
	{
		std::vector<int> sav;

		if (line == 1)
		{
			sav = this->line1;
			this->set_line1(obj3->get_line1());
			obj3->set_line1(obj2->get_line1());
			obj2->set_line1(obj1->get_line1());
			obj1->set_line1(sav);
		}
		else if (line == 3)
		{
			sav = this->line3;
			this->set_line3(obj3->get_line3());
			obj3->set_line3(obj2->get_line3());
			obj2->set_line3(obj1->get_line3());
			obj1->set_line3(sav);
		}
	}

	void Face::rotat_right_col(int col, Face *obj1, Face *obj2, Face *obj3)
	{
		std::vector<int> sav;

		if (col == 3)
		{
			sav = this->col3;
			this->set_col3(obj3->get_line1());
			obj3->set_line1(this->get_rev_list(obj2->get_col1()));
			obj2->set_col1(obj1->get_line3());
			obj1->set_line3(this->get_rev_list(sav));
		}
		else if (col == 1)
		{
			sav = this->col1;
			this->set_col1(obj3->get_line3());
			obj3->set_line3(this->get_rev_list(obj2->get_col3()));
			obj2->set_col3(obj1->get_line1());
			obj1->set_line1(this->get_rev_list(sav));
		}
	}

	void Face::rotat_left_col(int col, Face *obj1, Face *obj2, Face *obj3)
	{
		std::vector<int> sav;

		if (col == 3)
		{
			sav = this->col3;
			this->set_col3(this->get_rev_list(obj1->get_line3()));
			obj1->set_line3(obj2->get_col1());
			obj2->set_col1(this->get_rev_list(obj3->get_line1()));
			obj3->set_line1(sav);
		}
		else if (col == 1)
		{
			sav = this->col1;
			this->set_col1(this->get_rev_list(obj1->get_line1()));
			obj1->set_line1(obj2->get_col3());
			obj2->set_col3(this->get_rev_list(obj3->get_line3()));
			obj3->set_line3(sav);
		}
	}



	void Face::rotat_right_coll(int col, Face *obj1, Face *obj2, Face *obj3)
	{
		std::vector<int> sav;

		if (col == 3)
		{
			sav = this->col3;
			this->set_col3(obj3->get_col3());
			obj3->set_col3(this->get_rev_list(obj2->get_col1()));
			obj2->set_col1(this->get_rev_list(obj1->get_col3()));
			obj1->set_col3(sav);
		}
		else if (col == 1)
		{
			sav = this->col1;
			this->set_col1(obj3->get_col1());
			obj3->set_col1(this->get_rev_list(obj2->get_col3()));
			obj2->set_col3(this->get_rev_list(obj1->get_col1()));
			obj1->set_col1(sav);
		}
	}

	void Face::rotat_left_coll(int col, Face *obj1, Face *obj2, Face *obj3)
	{
		std::vector<int> sav;

		if (col == 3)
		{
			sav = this->col3;
			this->set_col3(obj3->get_col3());
			obj3->set_col3(this->get_rev_list(obj2->get_col1()));
			obj2->set_col1(this->get_rev_list(obj1->get_col3()));
			obj1->set_col3(sav);
		}
		else if (col == 1)
		{
			sav = this->col1;
			this->set_col1(obj3->get_col1());
			obj3->set_col1(this->get_rev_list(obj2->get_col3()));
			obj2->set_col3(this->get_rev_list(obj1->get_col1()));
			obj1->set_col1(sav);
		}
		}




	void Face::rotat_left_face()
	{
		this->set_col1(this->get_rev_list(this->line1));
		this->set_col2(this->get_rev_list(this->line2));
		this->set_col3(this->get_rev_list(this->line3));
	}
	
	void Face::rotat_right_face()
	{
		this->set_col3(this->line1);
		this->set_col2(this->line2);
		this->set_col1(this->line3);
	}

	void Face::set_update_l(int val)
	{
		this->update_l.push_back(val);
	}

	void Face::set_update_c(int val)
	{
		this->update_c.push_back(val);
	}


	std::vector<int> Face::get_rev_list(std::vector<int> lst)
	{
		std::vector<int> ret;

		for (std::vector<int>::iterator it=lst.begin(); it != lst.end(); ++it)
		{
			ret.insert(ret.begin() ,*it);
		}
		return ret;
	}

	void Face::fusion_ligne_col()
	{
		int i = 0;

		for (std::vector<int>::iterator it=this->update_l.begin(); it != this->update_l.end(); ++it)
		{
			if (*it == 1)
			{
				this->col1.erase (col1.begin());
				this->col2.erase (col2.begin());
				this->col3.erase (col3.begin());
				this->col1.insert(col1.begin(), this->line1[0]);
				this->col2.insert(col2.begin(), this->line1[1]);
				this->col3.insert(col3.begin(), this->line1[2]);
			}
			else if (*it == 2)
			{
				this->col1.erase (col1.begin() + 1);
				this->col2.erase (col2.begin() + 1);
				this->col3.erase (col3.begin() + 1);
				this->col1.insert(col1.begin() + 1, this->line2[0]);
				this->col2.insert(col2.begin() + 1, this->line2[1]);
				this->col3.insert(col3.begin() + 1, this->line2[2]);
			}
			else if (*it == 3)
			{
				this->col1.erase (col1.begin() + 2);
				this->col2.erase (col2.begin() + 2);
				this->col3.erase (col3.begin() + 2);
				this->col1.insert(col1.begin() + 2, this->line3[0]);
				this->col2.insert(col2.begin() + 2, this->line3[1]);
				this->col3.insert(col3.begin() + 2, this->line3[2]);
			}
		}
		for (std::vector<int>::iterator it=this->update_c.begin(); it != this->update_c.end(); ++it)
		{
			if (*it == 1)
			{
				this->line1.erase (line1.begin());
				this->line2.erase (line2.begin());
				this->line3.erase (line3.begin());
				this->line1.insert(line1.begin(), this->col1[0]);
				this->line2.insert(line2.begin(), this->col1[1]);
				this->line3.insert(line3.begin(), this->col1[2]);
			}
			else if (*it == 2)
			{
				this->line1.erase (line1.begin() + 1);
				this->line2.erase (line2.begin() + 1);
				this->line3.erase (line3.begin() + 1);
				this->line1.insert(line1.begin() + 1, this->col2[0]);
				this->line2.insert(line2.begin() + 1, this->col2[1]);
				this->line3.insert(line3.begin() + 1, this->col2[2]);
			}
			else if (*it == 3)
			{
				this->line1.erase (line1.begin() + 2);
				this->line2.erase (line2.begin() + 2);
				this->line3.erase (line3.begin() + 2);
				this->line1.insert(line1.begin() + 2, this->col3[0]);
				this->line2.insert(line2.begin() + 2, this->col3[1]);
				this->line3.insert(line3.begin() + 2, this->col3[2]);		
			}

		}
		this->update_l.erase(this->update_l.begin(), this->update_l.end());
		this->update_c.erase(this->update_c.begin(), this->update_c.end());
		}

	void Face::set_col1(std::vector<int> l)
	{
		this->col1 = l;
		this->set_update_c(1);
	}

	void Face::set_col2(std::vector<int> l)
	{
		this->col2 = l;
		this->set_update_c(2);
	}

	void Face::set_col3(std::vector<int> l)
	{
		this->col3 = l;
		this->set_update_c(3);
	}

	void Face::set_line1(std::vector<int> l)
	{
		this->line1 = l;
		this->set_update_l(1);
	}	
	
	void Face::set_line2(std::vector<int> l)
	{
		this->line2 = l;
		this->set_update_l(2);
	}

	void Face::set_line3(std::vector<int> l)
	{
		this->line3 = l;
		this->set_update_l(3);
	}

	std::vector<int> Face::get_line1()
	{
		return (this->line1);
	}
	
	std::vector<int> Face::get_line2()
	{
		return (this->line2);
	}
	
	std::vector<int> Face::get_line3()
	{
		return (this->line3);
	}

	std::vector<int> Face::get_col3()
	{
		return (this->col3);
	}

	std::vector<int> Face::get_col1()
	{
		return (this->col1);
	}

	std::vector<int> Face::get_col2()
	{
		return (this->col2);
	}


