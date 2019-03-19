#pragma once
#include "ArithmeticException.h"

// � ������ ����� ����������� ����������� �����, ������������ ��������� ������/����, ��� ������� ��������������� ������ �����������. ����� ����������� ������, ����������� ���������� ���������� �����/�����

namespace basic
{

	// TODO: � ����������� ���������� �������� ��������� ������ ��� ������� ������ ��������, ��������� �� ���������, ��� ����
	class IArithmetic
	{
	protected:
		double zero, one;
		virtual double getAddInverse(double a)
		{
			throw basic::ArithmeticException("this operation is unsupported for abstract field");
		}
		virtual double getMultInverse(double a)
		{
			throw basic::ArithmeticException("this operation is unsupported for abstract field");
		}


	public:
		IArithmetic(double zero, double one) : zero(zero), one(one) {};
		IArithmetic() {};

		virtual double summarize(double a, double b)
		{
			throw basic::ArithmeticException("this operation is unsupported for abstract field");
		}

		virtual double multiply(double a, double b) {
			throw basic::ArithmeticException("this operation is unsupported for abstract field");
		}

		double subtract(double a, double b) { return summarize(a, getAddInverse(b)); }

		double divide(double a, double b) {
			if(b==zero) throw basic::ArithmeticException("������� �� ����");
			return multiply(a, getMultInverse(b));
		}

		double power(double base, int exponent)
		{
			double cur = 1;
			for (int i = 0; i <= exponent; i++)
			{
				cur = multiply(cur, base);
			}
			return cur;
		}

		virtual bool belongs(double a)
		{
			throw basic::ArithmeticException("this operation is unsupported for abstract field");
		}

	};


	class TraditionalArithmetic : public IArithmetic
	{
	protected:
		double zero, one;
		double getAddInverse(double a) { return -1 * a; }
		double getMultInverse(double a) { return 1 / a; }

	public:
		TraditionalArithmetic() : one(1), zero(0) {};
		double summarize(double a, double b) { return a + b; };
		double multiply(double a, double b) { return a*b; };
		bool belongs(double a)
		{
			return true;
		}

	};

	// ��� ������-����������, �� �� 13.03.2019
	class Arithmetic1 : public IArithmetic
	{
	protected:
		double zero, one;
		double getAddInverse(double a) { 
			if(belongs(a)) return 2 - a; 
			else throw basic::ArithmeticException("������� �� ����������� �����");
		}
		virtual double multiply(double a, double b) {
			throw basic::ArithmeticException("�������� ��������� �� ���������� ��� ������� ����");
		}

	public:
		double summarize(double a, double b)
		{
			if (belongs(a) && belongs(b))
			{
				if (a + b < 2) return a + b;
				else return a + b - 2;
			}
			else throw basic::ArithmeticException("�������� �� ����������� ����");
		}
		Arithmetic1() : zero(0), one(1) {};
		bool belongs(double a)
		{
			return a < 2 && a >= 0;
		}

	};


}