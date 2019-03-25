#pragma once
#include "EquationSystem.h"
#include "Smalls.h"

namespace my_IO
{

	class PolynomialInitializer
	{
	private:
		char symb; // текущий символ
		int symb_place; // номер обрабатываемого символа
		int str_len; // длина входной строки
		std::string input; // обрабатываемая строка
		std::string str; // накапливаемая строка

		/*
					Отражает текущее состояние Машины. Принимает значения:
					0 - начальное состояние
					1 - выполняется парсинг коэффициента
					2 - выполняется парсинг названия переменной
					3 - выполняется начальный парсинг степени
					4 - конец парсинга
					5 - выполняется парсинг степени
					*/
		int state = 0;


		std::vector <basic::Polynomial> polynomials;
		int first_free_num;

		int monom_coeff; // коэффициент при читаемом мономе
		int base; // основание степени
		std::vector<std::pair<int, int>> grades; // степени монома

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





