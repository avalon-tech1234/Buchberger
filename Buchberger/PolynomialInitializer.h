#pragma once
#include "EquationSystem.h"

namespace my_IO
{

	class PolynomialInitializer
	{
	private:
		char symb; // ������� ������
		std::string input; // �������������� ������
		std::string str; // ������������� ������

		/*
					�������� ������� ��������� ������. ��������� ��������:
					0 - ��������� ���������
					1 - ����������� ������� ������������
					2 - ����������� ������� �������� ����������
					3 - ����������� ��������� ������� �������
					4 - ����� ��������
					5 - ����������� ������� �������
					6 - ������� ����������� (����� [ � ])
					*/
		int state = 0;


		int first_free_num;

		int monom_coeff; // ����������� ��� �������� ������
		int base; // ��������� �������
		std::vector<basic::Grade> grades; // ������� ������

		std::vector <basic::Monomial> monomials;


		inline int get_var_num(basic::Dictionary*);

		void cleanup();

		inline void to_state(int st);

		void pushMonomial(int last_base, int last_exp, bool is_end);
		void pushFreeMember(int);
		void setMonomCoeff(int symb_place, int a, basic::Arithmetics rules);
		void setGradeBase(basic::Dictionary*);
		void setGrade(int base, int exp);


	public:

		void inputPolynomial(basic::EquationSystem &, std::string source, basic::Arithmetics rules);



	};


}	





