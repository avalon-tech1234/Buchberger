#include "AppliedArithmetic.h"

using namespace arithmetics;

namespace basic
{
	double AppliedArithmetic::summarize(double a, double b, Arithmetics type)
	{
		switch (type) {
		case Arithmetics::TRADITIONAL: return TraditionalArithmetic::summarize(a, b);
		case Arithmetics::ARITHMETIC1: return Arithmetic1::summarize(a, b);
		default: throw ArithmeticException("Unsupported arithmetic used");
		}
	}

	double AppliedArithmetic::multiply(double a, double b, Arithmetics type)
	{
		switch (type) {
		case Arithmetics::TRADITIONAL: return TraditionalArithmetic::multiply(a, b);
		case Arithmetics::ARITHMETIC1: return Arithmetic1::multiply(a, b);
		default: throw ArithmeticException("Unsupported arithmetic used");
		}
	}

	double AppliedArithmetic::subtract(double a, double b, Arithmetics type)
	{
		switch (type) {
		case Arithmetics::TRADITIONAL: return TraditionalArithmetic::subtract(a, b);
		case Arithmetics::ARITHMETIC1: return Arithmetic1::subtract(a, b);
		default: throw ArithmeticException("Unsupported arithmetic used");
		}
	}

	double AppliedArithmetic::divide(double a, double b, Arithmetics type)
	{
		switch (type) {
		case Arithmetics::TRADITIONAL: return TraditionalArithmetic::divide(a, b);
		case Arithmetics::ARITHMETIC1: return Arithmetic1::divide(a, b);
		default: throw ArithmeticException("Unsupported arithmetic used");
		}
	}

	double AppliedArithmetic::power(double a, int exp, Arithmetics type)
	{
		switch (type) {
		case Arithmetics::TRADITIONAL: return TraditionalArithmetic::power(a, exp);
		case Arithmetics::ARITHMETIC1: return Arithmetic1::power(a, exp);
		default: throw ArithmeticException("Unsupported arithmetic used");
		}
	}

	bool AppliedArithmetic::belongs(double a, Arithmetics type)
	{
		switch (type) {
		case Arithmetics::TRADITIONAL: return TraditionalArithmetic::belongs(a);
		case Arithmetics::ARITHMETIC1: return Arithmetic1::belongs(a);
		default: throw ArithmeticException("Unsupported arithmetic used");
		}
	}
}