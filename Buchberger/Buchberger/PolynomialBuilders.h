#pragma once
#include "EquationSystem.h"

namespace my_IO
{

	class IEquationSystemBuilder
	{
	protected:
		char symb; // ������� ������
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


		std::vector <my_algorithm::Polynomial> polynomials;
		std::map<std::string, int> var_dic;
		int first_free_num;

		int monom_coeff; // ����������� ��� �������� ������
		int base; // ��������� �������
		std::vector<std::pair<int, int>> grades; // ������� ������

		std::vector <my_algorithm::Monomial> monomials;

		bool issign();
		bool istrail();
		bool iscap();
		bool isdig();
		bool isalph();
		bool isempty();

		int get_var_num();

		void to_state(int st);
		void pushMonomial(int last_base, int last_exp, bool is_end);
		void pushFreeMember(int);
		void setMonomCoeff(int a);
		void setGradeBase();
		void setGrade(int base, int exp);

		virtual void get_new_symb() = 0;

	public:

		void inputPolynomial(my_algorithm::Polynomial &);
		std::map<std::string, int> getVariablesDictionary() { return var_dic; }

	};

	class ConsoleEquationSystemBuilder : public IEquationSystemBuilder
	{
	private:
		void get_new_symb();
	};

	class StringEquationSystemBuilder : public IEquationSystemBuilder
	{

	private:
		std::string input;
		size_t cur_symb;
		size_t str_len;

		void get_new_symb()
		{
			if (cur_symb < str_len)
			{
				symb = input[cur_symb];
				cur_symb++;
			}
			else
			{
				symb = '\n';
			}
		}

	public:
		StringEquationSystemBuilder(std::string input) : input(input), cur_symb(0), str_len(input.size()) {};

	};

}