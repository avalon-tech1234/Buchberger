#pragma once
#include "EquationSystem.h"

namespace my_IO
{
	class Writer
	{
	public:
		static void writePolynomialValues(const basic::EquationSystem& sys, const std::vector<double>& result, std::string input, std::string output);
	};
}