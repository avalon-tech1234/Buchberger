#pragma once
#include "EquationSystem.h"

namespace my_IO
{

	class PolynomialInitializer
	{
	private:
		char symb; // текущий символ
		std::string input; // обрабатываема€ строка
		std::string str; // накапливаема€ строка

		/*
					ќтражает текущее состо€ние ћашины. ѕринимает значени€:
					0 - начальное состо€ние
					1 - выполн€етс€ парсинг коэффициента
					2 - выполн€етс€ парсинг названи€ переменной
					3 - выполн€етс€ начальный парсинг степени
					4 - конец парсинга
					5 - выполн€етс€ парсинг степени
					6 - парсинг комментари€ (между [ и ])
					*/
		int state = 0;


		int first_free_num;

		int monom_coeff; // коэффициент при читаемом мономе
		int base; // основание степени
		std::vector<basic::Grade> grades; // степени монома

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





