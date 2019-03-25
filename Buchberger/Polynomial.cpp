#include "Polynomial.h"

namespace basic
{
	double Polynomial::substitute(ValuesList list, Arithmetics rules)
	{
		double result = 0;
		for (int i = 0; i < size(); i++)
		{
			result += operator[](i).substitute(list, rules);
		}
		return result;
	}

}