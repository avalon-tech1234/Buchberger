#pragma once
#include "EquationSystem.h"

namespace my_IO
{
	class EnvironmentInitializer
	{
	public:

	void initialize(basic::EquationSystem* sys);
	
	void assignArithmetic(basic::EquationSystem* sys);

	};
}