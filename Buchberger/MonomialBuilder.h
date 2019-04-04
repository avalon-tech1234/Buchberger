#pragma once
#include <vector>
#include "Monomial.h"

// Класс, используемый при построчном парсинге файла с полиномами. Используется как база для наследования классом PolynomialBuilder, а он уже инкапсулируется в Parser

namespace my_IO
{
	class MonomialBuilder
	{
	private:
		int monom_coeff; // коэффициент при читаемом мономе
		std::vector<basic::Grade> grades; // степени монома
		basic::Monomial mon;
	protected:
		void clean()
		{
			std::vector<basic::Grade>().swap(grades);
			monom_coeff = 0;
		}

		virtual const basic::Monomial& createMonomial()
		{
			return createMonomial(monom_coeff, grades);
		}
		virtual const basic::Monomial& createMonomial(int mk, std::vector<basic::Grade>& gr = std::vector<basic::Grade>())
		{
			mon = basic::Monomial(mk, gr);
			clean();
			return mon;
		}


	public:
		void setCoeff(int coeff)
		{
			monom_coeff = coeff;
		}
		virtual void addGrade(basic::Grade grade)
		{
			grades.push_back(grade);
		}
	};


}
