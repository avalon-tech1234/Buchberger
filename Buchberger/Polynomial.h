#pragma once
#include "Monomial.h"


namespace basic {


	class Polynomial : public std::vector <Monomial>
	{
	private:
		Monomial leadingMonomial;

		void refreshLeadingMonomial() { leadingMonomial = getLeadingMonomial(); };

	public:
		Polynomial(std::vector <Monomial> in_monomials): std::vector <Monomial>(in_monomials) {};

		Polynomial() {}

		Monomial getLeadingMonomial();

		double substitute(const std::vector<double> values, const basic::IArithmetic* rules);

	};
}

