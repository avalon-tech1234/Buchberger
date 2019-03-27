#pragma once
#include "Smalls.h"



namespace basic {

	class Monomial : public std::vector< Grade >
	{
	private:

		int coeff; //коэффициент при мономе

	public:

		Monomial(int coeff, std::vector< Grade > in_grades);
		Monomial() {};

		double substitute(ValuesList, basic::Arithmetics);

		friend int compare(const Monomial& m1, const Monomial& m2);
		friend bool operator == (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) == 0; }
		friend bool operator != (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) != 0; }
		friend bool operator < (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) == -1; }
		friend bool operator > (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) == 1; }
		friend bool operator <= (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) <= 0; }
		friend bool operator >= (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) >= 0; }

	};
}