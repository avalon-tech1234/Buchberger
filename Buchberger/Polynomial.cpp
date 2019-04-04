#include "Polynomial.h"

namespace basic
{
	double Polynomial::substitute(const vector<double> values, const basic::IArithmetic* rules)
	{
		double result = 0;
		size_t s = size();
		for (size_t i = 0; i < s; i++)
		{
			double plus = operator[](i).substitute(values, rules);
			result = rules->summarize(result, plus);
		}
		return result;
	}

}