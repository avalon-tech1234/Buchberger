#include "VariableValueInitializer.h"
#include "ParsingException.h"
#include "Utility.h"


using namespace std;
using namespace basic;

namespace my_IO
{
	void VariableValueInitializer::inputVariableValue(VariablesMap & vs, string source, Arithmetics rules)
	{
		int place = source.find('=');
		string var_name = trim_copy(source.substr(0, place));
		string str_val = trim_copy(source.substr(place+1));
		double var_val = stod(str_val);
		vs.addVariable(var_name, var_val);
	}
}