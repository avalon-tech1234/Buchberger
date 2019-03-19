#pragma once
#include "ArithmeticException.h"

// В данном файле описывается абстрактный класс, определяющий некоторое кольцо/поле, над которым рассматривается кольцо многочленов. Далее описываются классы, описывающие устройство конкретных полей/колец

namespace basic
{

	// TODO: в реализациях Арифметики дописать обработку ошибки при попытке взятия элемента, обратного по умножению, для нуля
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
			if(b==zero) throw basic::ArithmeticException("деление на нуль");
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

	// для Сергея-математика, ТЗ от 13.03.2019
	class Arithmetic1 : public IArithmetic
	{
	protected:
		double zero, one;
		double getAddInverse(double a) { 
			if(belongs(a)) return 2 - a; 
			else throw basic::ArithmeticException("операнд не принадлежит полям");
		}
		virtual double multiply(double a, double b) {
			throw basic::ArithmeticException("операция умножения не определена для данного поля");
		}

	public:
		double summarize(double a, double b)
		{
			if (belongs(a) && belongs(b))
			{
				if (a + b < 2) return a + b;
				else return a + b - 2;
			}
			else throw basic::ArithmeticException("операнды не принадлежат полю");
		}
		Arithmetic1() : zero(0), one(1) {};
		bool belongs(double a)
		{
			return a < 2 && a >= 0;
		}

	};


}