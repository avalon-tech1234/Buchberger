#pragma once
#include "ArithmeticException.h"

// � ������ ����� ����������� ����������� �����, ������������ ��������� ������/����, ��� ������� ��������������� ������ �����������.
// ����� ����������� ������, ����������� ���������� ���������� �����/�����

namespace basic
{

	// TODO: ������� ������� � �������

	
	class IArithmetic
	{
	protected:
		double e_divide(double a, double b, double zero) const;

	public:
		virtual double getAddInverse(double a) const;
		virtual double getMultInverse(double a) const;
		virtual double summarize(double a, double b) const;
		virtual double multiply(double a, double b) const;
		virtual double subtract(double a, double b) const;
		virtual bool belongs(double a) const;

		double power(double base, int exponent) const;
	};

	

	class TraditionalArithmetic : public IArithmetic
	{
	public:
		double getAddInverse(double a) const { return -1 * a; }
		double getMultInverse(double a) const;
		double summarize(double a, double b) const { return a + b; };
		double multiply(double a, double b) const { return a*b; };
		double divide(double a, double b) const { return e_divide(a, b, 0); }
		bool belongs(double a) const { return true; }
	};

	// ��� ������-����������, �� �� 13.03.2019
	class Arithmetic1 : public IArithmetic
	{
	public:
		double getAddInverse(double a) const;
		double summarize(double a, double b) const;
		double multiply(double a, double b) const;
		bool belongs(double a) const;
		double divide(double a, double b) const;

	};
}