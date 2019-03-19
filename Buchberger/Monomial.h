#pragma once
#include <vector>
#include "Arithmetics.h"



namespace basic {

	class Monomial
	{
	private:

		int coeff; //коэффициент при мономе
		std::vector< std::pair<int, int> > grades; // вектор степеней
		Arithmetic1 a;

	public:
		Monomial(int coeff, std::vector< std::pair<int, int> > grades);
		Monomial(const Monomial &m) : grades(m.grades), coeff(m.coeff), a() {};
		Monomial() {};
		~Monomial() { std::vector<std::pair<int, int>>().swap(grades); }

		friend int compare(const Monomial& m1, const Monomial& m2);
		friend bool operator == (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) == 0; }
		friend bool operator != (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) != 0; }
		friend bool operator < (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) == -1; }
		friend bool operator > (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) == 1; }
		friend bool operator <= (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) <= 0; }
		friend bool operator >= (const Monomial& m1, const Monomial& m2) { return compare(m1, m2) >= 0; }

	};
}