#ifndef FACE_HPP
# define FACE_HPP

#include <iostream>
#include <vector>

class Face
{
	public:
		Face();
		Face(int c);
		Face( Face const & src );
		~Face( void );
		std::vector<std::string> print_face() const;
		void rotat_left_line(int line, Face *obj1, Face *obj2, Face *obj3);
		void rotat_right_line(int line, Face *obj1, Face *obj2, Face *obj3);
		void rotat_right_col(int col, Face *obj1, Face *obj2, Face *obj3);
		void rotat_left_col(int col, Face *obj1, Face *obj2, Face *obj3);
		void rotat_right_coll(int col, Face *obj1, Face *obj2, Face *obj3);
		void rotat_left_coll(int col, Face *obj1, Face *obj2, Face *obj3);
		void rotat_right_face();
		void rotat_left_face();
		void fusion_ligne_col();
		std::vector<int> get_line1();
		std::vector<int> get_line2();
		std::vector<int> get_line3();
		std::vector<int> get_col1();
		std::vector<int> get_col2();
		std::vector<int> get_col3();
		std::vector<int> get_rev_list(std::vector<int> lst);


	private:
		void set_line1(std::vector<int> l);
		void set_line2(std::vector<int> l);
		void set_line3(std::vector<int> l);
		void set_col1(std::vector<int> l);
		void set_col2(std::vector<int> l);
		void set_col3(std::vector<int> l);
		void set_update_l(int val);
		void set_update_c(int val);
		std::string get_line(std::vector<int> l) const;

		/* atribue */
		std::vector<int> line1;
		std::vector<int> line2;
		std::vector<int> line3;
		std::vector<int> col1;
		std::vector<int> col2;
		std::vector<int> col3;
		std::vector<int> update_l;
		std::vector<int> update_c;

};


#endif
