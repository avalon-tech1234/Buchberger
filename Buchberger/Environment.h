#pragma once
#include "EquationSystem.h"
#include "Smalls.h"

namespace my_IO
{
	class Environment
	{
	private:

	static void initialize_system(basic::EquationSystem& sys, basic::Arithmetics rules);

	static void initialize_variables(basic::VariablesMap& var_set, basic::Arithmetics rules);

	public:
		static void initialize_environment(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules);

		static void substitute(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules);
	
	};
}