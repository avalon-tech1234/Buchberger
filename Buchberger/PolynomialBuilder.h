#pragma once
#include "MonomialBuilder.h"

namespace my_IO
{
	class PolynomialBilder : public MonomialBuilder
	{
	private:
		std::vector <basic::Monomial> monomials;
		basic::Polynomial pol;

	public:

		virtual void addMonomial()
		{
			monomials.push_back(MonomialBuilder::createMonomial());
		}

		void addMonomial(int mk, std::vector<basic::Grade>& gr = std::vector<basic::Grade>())
		{
			monomials.push_back(MonomialBuilder::createMonomial(mk, gr));

		}

		const basic::Polynomial& createPolynomial()
		{
			pol = basic::Polynomial(monomials);
			std::vector<basic::Monomial>().swap(monomials);
			return pol;
		}
	};
}
