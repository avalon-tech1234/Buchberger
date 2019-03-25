#pragma once
#include "ArithmeticException.h"

// В данном файле описывается абстрактный класс, определяющий некоторое кольцо/поле, над которым рассматривается кольцо многочленов.
// Далее описываются классы, описывающие устройство конкретных полей/колец

namespace arithmetics
{

	// TODO: в реализациях Арифметики добавить везде проверку на то, что оба операнда принадлежат полю

	
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

	// для Сергея-математика, ТЗ от 13.03.2019
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