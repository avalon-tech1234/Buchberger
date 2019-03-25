#pragma once
#include "EquationSystem.h"

namespace my_IO
{
	class Writer
	{
	public:
		static void writePolynomialValues(basic::EquationSystem& sys, std::vector<double> result, std::string input, std::string output);
	};
}