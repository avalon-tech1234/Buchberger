#pragma once
#include "Arithmetics.h"

// в этом файле описана структура AppliedArithmeic, запускающая нужную (в зависимости от текущей арифметики) операцию.
// Сами операции описаны в Arithmetics.h.
// Также в этом файле описано перечисление ArithmeticTypes, в котором перечислены возможные арифметики
// Важно! Надо вручную поддерживать связь между перечислением и фактическими арифметиками


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