#pragma once
#include "EquationSystem.h"



class Environment
{
private:

	basic::EquationSystem system;
	basic::IArithmetic* rules;
	std::vector<double> values;

	void initialize_system();
	void initialize_variables();

public:

	bool initialize_everything();
	void substitute();

	Environment(): rules(), system(rules)
	{
		rules = new basic::Arithmetic1();
		system = basic::EquationSystem(rules);
	}

};
