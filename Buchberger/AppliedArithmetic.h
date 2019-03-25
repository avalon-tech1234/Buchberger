#pragma once
#include "Arithmetics.h"

// � ���� ����� ������� ��������� AppliedArithmeic, ����������� ������ (� ����������� �� ������� ����������) ��������.
// ���� �������� ������� � Arithmetics.h.
// ����� � ���� ����� ������� ������������ ArithmeticTypes, � ������� ����������� ��������� ����������
// �����! ���� ������� ������������ ����� ����� ������������� � ������������ ������������


namespace basic
{
	enum class Arithmetics
	{
		TRADITIONAL,
		ARITHMETIC1
	};

	struct AppliedArithmetic
	{

	public:
		static double summarize(double a, double b, Arithmetics rules);
		static double multiply(double a, double b, Arithmetics rules);
		static double subtract(double a, double b, Arithmetics rules);
		static double divide(double a, double b, Arithmetics rules);
		static double power(double base, int exponent, Arithmetics rules);

		static bool belongs(double a, Arithmetics rules);

	};
}