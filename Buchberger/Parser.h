#pragma once
#include "EquationSystem.h"


namespace my_IO
{
	class Parser
	{

	public:

		static void inputPolynomial(basic::EquationSystem &, const std::string source);

		static std::pair<std::string, double> inputVariableValue(const basic::IArithmetic* rules, std::string source);

	};


}	





