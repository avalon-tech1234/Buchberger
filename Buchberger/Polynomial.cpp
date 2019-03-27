#include "Polynomial.h"

namespace basic
{
	double Polynomial::substitute(ValuesList list, Arithmetics rules)
	{
		double result = 0;
		size_t s = size();
		for (size_t i = 0; i < s; i++)
		{
			double plus = operator[](i).substitute(list, rules);
			result = AppliedArithmetic::summarize(result, plus, rules);
		}
		return result;
	}

}