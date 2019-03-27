#pragma once
#include "EquationSystem.h"

namespace my_IO
{
	class Environment
	{
	private:

	static bool initialize_system(basic::EquationSystem& sys, basic::Arithmetics rules);

	static bool initialize_variables(basic::VariablesMap& var_set, basic::Arithmetics rules);

	public:
		static bool initialize_environment(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules);

		static bool substitute(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules);
	
	};
}