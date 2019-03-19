#include <algorithm>
#include "Monomial.h"


using namespace std;

namespace basic
{
	Monomial::Monomial(int coeff, std::vector< std::pair<int, int> > in_grades) : coeff(coeff)
	{
		sort(in_grades.begin(), in_grades.end());
		grades = in_grades;
		a = Arithmetic1();
	}

	// 0 равны, 1 первый больше, -1 второй больше
	int compare(const Monomial& m1, const Monomial& m2)
	{
		size_t i1 = 0, i2 = 0;
		size_t i1_max = m1.grades.size(), i2_max = m1.grades.size();
		while (i1 < i1_max, i2 < i2_max)
		{
			if (m1.grades[i1].first > m2.grades[i2].first) return -1;
			if (m1.grades[i1].first < m2.grades[i2].first) return 1;
			if (m1.grades[i1].second > m2.grades[i2].second) return 1;
			if (m1.grades[i1].second < m2.grades[i2].second) return -1;
		}
		if (i1 < i1_max) return 1;
		if (i2 < i2_max) return -1;
		return 0;
	}


}