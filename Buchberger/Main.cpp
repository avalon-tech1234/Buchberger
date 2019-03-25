#include "PolynomialInitializer.h"
#include "Environment.cpp"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace basic;
using namespace my_IO;


int main()
{
	//const string test_str = "2x1^3x4^2 +4x3   + 7";
	setlocale(0, "");


	try {
		EquationSystem sys;
		VariablesMap vars;
		Arithmetics rules = Arithmetics::ARITHMETIC1;
		Environment::initialize_environment(sys, vars, rules);
		Environment::substitute(sys, vars, rules);
	}
	catch (exception& e)
	{
		cout << "Произошла ошибка. Текст ошибки: " << e.what() << endl;
	}

	system("pause");
	return 0;
}