#pragma once
#include "EquationSystem.h"

namespace my_IO
{

	class PolynomialInitializer
	{
	protected:
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

		inline bool issign();
		inline bool istrail();
		inline bool iscap();
		inline bool isdig();
		inline bool isalph();
		inline bool isempty();

		inline int get_var_num(std::map<std::string, int>*);

		void cleanup();

		inline void to_state(int st);

		void pushMonomial(int last_base, int last_exp, bool is_end);
		void pushFreeMember(int);
		void setMonomCoeff(int a);
		void setGradeBase(std::map<std::string, int>*);
		void setGrade(int base, int exp);


	public:

		//void inputEquationSystem(my_algorithm::EquationSystem* s);
		void inputPolynomial(basic::EquationSystem &, std::string source);

	};


}	





