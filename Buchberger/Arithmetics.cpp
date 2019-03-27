#include "Arithmetics.h"

using namespace basic;

namespace arithmetics
{
	double IArithmetic::getAddInverse(double a)
	{
		throw ArithmeticException("additional inverting operation is unsupported for this field");
	}

	double IArithmetic::getMultInverse(double a)
	{
		throw ArithmeticException("multiplicational inverting operation is unsupported for this field");
	}

	double IArithmetic::summarize(double a, double b)
	{
		throw ArithmeticException("addition is unsupported for this field");
	}

	double IArithmetic::multiply(double a, double b) 
	{
		throw ArithmeticException("multiplication is unsupported for this field");
	}

	double IArithmetic::subtract(double a, double b)
	{
		return summarize(a, getAddInverse(b));
	}

	double IArithmetic::e_divide(double a, double b, double zero)
	{
		if (b == zero) throw ArithmeticException("деление на нуль");
		return multiply(a, getMultInverse(b));
	}

	double IArithmetic::power(double base, int exponent)
	{
		double cur = 1;
		for (int i = 0; i <= exponent; i++)
		{
			cur = multiply(cur, base);
		}
		return cur;
	}

	bool IArithmetic::belongs(double a)
	{
		throw ArithmeticException("checking if belongs operation is unsupported for this field");
	}

	double TraditionalArithmetic::getMultInverse(double a)
	{
		if (a == 0) throw ArithmeticException("деление на нуль");
		return 1 / a; 
	}

	double Arithmetic1::getAddInverse(double a)
	{
		if (belongs(a)) return 2 - a;
		else throw ArithmeticException("операнд не принадлежит полю");
	}

	double Arithmetic1::multiply(double a, double b)
	{
		if (belongs(a) && belongs(b))
		{
			if (a <= 1 && b <= 1) return a*b;
			if (a > 1 && b <= 1) return 2 - (2 - a)*b;
			if (a <= 1 && b > 1) return 2 - a*(2-b);
			else return (2-a)*(2-b);
		}
		else throw ArithmeticException("операнды не принадлежат полю");
	}

	double Arithmetic1::summarize(double a, double b)
	{
		if (belongs(a) && belongs(b))
		{
			if (a + b < 2) return a + b;
			else return a + b - 2;
		}
		else throw ArithmeticException("операнды не принадлежат полю");
	}

	bool Arithmetic1::belongs(double a)
	{
		return a < 2 && a >= 0;
	}

	double Arithmetic1::divide(double a, double b) 
	{ 
		throw basic::ArithmeticException("для этого поля деление не поддерживается"); 
	}

	double Arithmetic1::power(double base, int exponent)
	{
		double cur = 1;
		for (int i = 0; i < exponent; i++)
		{
			cur = multiply(cur, base);
		}
		return cur;
	}


}