#include "Arithmetics.h"

using namespace basic;

namespace basic
{
	double IArithmetic::getAddInverse(double a) const
	{
		throw ArithmeticException("additional inverting operation is unsupported for this field");
	}

	double IArithmetic::getMultInverse(double a) const
	{
		throw ArithmeticException("multiplicational inverting operation is unsupported for this field");
	}

	double IArithmetic::summarize(double a, double b) const
	{
		throw ArithmeticException("addition is unsupported for this field");
	}

	double IArithmetic::multiply(double a, double b) const
	{
		throw ArithmeticException("multiplication is unsupported for this field");
	}

	double IArithmetic::subtract(double a, double b) const
	{
		return summarize(a, getAddInverse(b));
	}

	double IArithmetic::e_divide(double a, double b, double zero) const
	{
		if (b == zero) throw ArithmeticException("������� �� ����");
		return multiply(a, getMultInverse(b));
	}

	double IArithmetic::power(double base, int exponent) const
	{
		double cur = 1;
		for (int i = 0; i < exponent; i++)
		{
			cur = multiply(cur, base);
		}
		return cur;
	}

	bool IArithmetic::belongs(double a) const 
	{
		throw ArithmeticException("checking if belongs operation is unsupported for this field");
	}

	double TraditionalArithmetic::getMultInverse(double a) const
	{
		if (a == 0) throw ArithmeticException("������� �� ����");
		return 1 / a; 
	}

	double Arithmetic1::getAddInverse(double a) const
	{
		if (belongs(a)) return 2 - a;
		else throw ArithmeticException("������� �� ����������� ����");
	}

	double Arithmetic1::multiply(double a, double b) const
	{
		if (belongs(a) && belongs(b))
		{
			if (a <= 1 && b <= 1) return a*b;
			if (a > 1 && b <= 1) return 2 - (2 - a)*b;
			if (a <= 1 && b > 1) return 2 - a*(2-b);
			else return (2-a)*(2-b);
		}
		else throw ArithmeticException("�������� �� ����������� ����");
	}

	double Arithmetic1::summarize(double a, double b) const
	{
		if (belongs(a) && belongs(b))
		{
			if (a + b < 2) return a + b;
			else return a + b - 2;
		}
		else throw ArithmeticException("�������� �� ����������� ����");
	}

	bool Arithmetic1::belongs(double a) const
	{
		return a < 2 && a >= 0;
	}

	double Arithmetic1::divide(double a, double b) const
	{ 
		throw basic::ArithmeticException("��� ����� ���� ������� �� ��������������"); 
	}

}