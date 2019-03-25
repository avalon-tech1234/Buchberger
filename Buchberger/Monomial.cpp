#include <algorithm>
#include "Monomial.h"


using namespace std;

namespace basic
{
	Monomial::Monomial(int coeff, vector<pair<int, int> > in_grades) : coeff(coeff)
	{
		sort(in_grades.begin(), in_grades.end());
		for (int i = 0; i < in_grades.size(); i++)
		{
			push_back(in_grades[i]);
		}
	}

	// 0 равны, 1 первый больше, -1 второй больше
	int compare(const Monomial& m1, const Monomial& m2)
	{
		size_t i1 = 0, i2 = 0;
		size_t i1_max = m1.size(), i2_max = m1.size();
		while (i1 < i1_max, i2 < i2_max)
		{
			if (m1[i1].first > m2[i2].first) return -1;
			if (m1[i1].first < m2[i2].first) return 1;
			if (m1[i1].second > m2[i2].second) return 1;
			if (m1[i1].second < m2[i2].second) return -1;
		}
		if (i1 < i1_max) return 1;
		if (i2 < i2_max) return -1;
		return 0;
	}

	// TODO: оптимизировать поиск с учетом того, что массив отсортирован
	double Monomial::substitute(ValuesList list, Arithmetics rules)
	{
		double result = 1;
		for (int i = 0; i < size(); i++)
		{
			result *= AppliedArithmetic::power(list.find(operator[](i).first)->second, operator[](i).second, rules);
		}
		return result*coeff;
	}

}