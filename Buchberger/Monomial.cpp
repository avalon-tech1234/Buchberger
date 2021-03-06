#include <algorithm>
#include "Monomial.h"


using namespace std;

namespace basic
{
	Monomial::Monomial(int coeff, vector<Grade > in_grades) : coeff(coeff)
	{
		sort(in_grades.begin(), in_grades.end(), Grade::compare_in_list);
		size_t s = in_grades.size();
		for (size_t i = 0; i < s; i++)
		{
			push_back(in_grades[i]);
		}
	}

	// 0 �����, 1 ������ ������, -1 ������ ������
	int compare(const Monomial& m1, const Monomial& m2)
	{
		size_t i1 = 0, i2 = 0;
		size_t i1_max = m1.size(), i2_max = m1.size();
		while (i1 < i1_max, i2 < i2_max)
		{
			if (m1[i1].base > m2[i2].base) return -1;
			if (m1[i1].base < m2[i2].base) return 1;
			if (m1[i1].exp > m2[i2].exp) return 1;
			if (m1[i1].exp < m2[i2].exp) return -1;
		}
		if (i1 < i1_max) return 1;
		if (i2 < i2_max) return -1;
		return 0;
	}

	double Monomial::substitute(const vector<double> values, const basic::IArithmetic* rules)
	{
		double result = 1;
		double base, pow;
		int exp;
		size_t s = size();
		for (size_t i = 0; i < s; i++)
		{
			base = values[operator[](i).base];
			exp = operator[](i).exp;
			pow = rules->power(base, exp);
			result = rules->multiply(result, pow);
		}
		return result*coeff;
	}

}