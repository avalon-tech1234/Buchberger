#pragma once
#include "EquationSystem.h"
#include "Smalls.h"

namespace my_IO
{

	class PolynomialInitializer
	{
	private:
		char symb; // ������� ������
		int symb_place; // ����� ��������������� �������
		int str_len; // ����� ������� ������
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
					*/
		int state = 0;


		std::vector <basic::Polynomial> polynomials;
		int first_free_num;

		int monom_coeff; // ����������� ��� �������� ������
		int base; // ��������� �������
		std::vector<std::pair<int, int>> grades; // ������� ������

		std::vector <basic::Monomial> monomials;


		inline int get_var_num(basic::Dictionary*);

		void cleanup();

		inline void to_state(int st);

		void pushMonomial(int last_base, int last_exp, bool is_end);
		void pushFreeMember(int);
		void setMonomCoeff(int a, basic::Arithmetics rules);
		void setGradeBase(basic::Dictionary*);
		void setGrade(int base, int exp);


	public:

		void inputPolynomial(basic::EquationSystem &, std::string source, basic::Arithmetics rules);



	};


}	





