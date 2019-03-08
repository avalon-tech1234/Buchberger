#include "Polynomial.h"
#include <algorithm>


namespace my_algorithm
{
	Monomial::Monomial(int coeff, std::vector< std::pair<int, int> > in_grades) : coeff(coeff)
	{
		sort(in_grades.begin(), in_grades.end());
		grades = in_grades;
	}
}