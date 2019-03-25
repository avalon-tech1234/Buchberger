#pragma once
#include "ArithmeticException.h"

// � ������ ����� ����������� ����������� �����, ������������ ��������� ������/����, ��� ������� ��������������� ������ �����������.
// ����� ����������� ������, ����������� ���������� ���������� �����/�����

namespace arithmetics
{

	// TODO: � ����������� ���������� �������� ����� �������� �� ��, ��� ��� �������� ����������� ����

	
	struct IArithmetic
	{
	protected:
		static double e_divide(double a, double b, double zero);

	public:
		static double getAddInverse(double a);
		static double getMultInverse(double a);
		static double summarize(double a, double b);
		static double multiply(double a, double b);
		static double subtract(double a, double b);
		static double power(double base, int exponent);
		static bool belongs(double a);
	};

	

	struct TraditionalArithmetic : public IArithmetic
	{
	public:
		static double getAddInverse(double a) { return -1 * a; }
		static double getMultInverse(double a);
		static double summarize(double a, double b) { return a + b; };
		static double multiply(double a, double b) { return a*b; };
		static double divide(double a, double b) { return e_divide(a, b, 0); }
		static bool belongs(double a) { return true; }
	};

	// ��� ������-����������, �� �� 13.03.2019
	class Arithmetic1 : public IArithmetic
	{
	public:
		static double getAddInverse(double a);
		static double summarize(double a, double b);
		static double multiply(double a, double b);
		static bool belongs(double a);
		static double divide(double a, double b);

		static double power(double base, int exponent);

	};
}