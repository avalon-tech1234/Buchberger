#pragma once
#include "Monomial.h"

namespace basic {


	class Polynomial
	{
	private:
		std::vector <Monomial> monomials;
		Monomial leadingMonomial;

		void refreshLeadingMonomial() { leadingMonomial = getLeadingMonomial(); };

	public:
		Polynomial(std::vector <Monomial> in_monomials): monomials(in_monomials) {};
		Polynomial() {};
		~Polynomial()
		{
			std::vector<Monomial>().swap(monomials);
		}

		void remove_empty(); //удаление пустых мономов
		Monomial getLeadingMonomial();

	};
}

