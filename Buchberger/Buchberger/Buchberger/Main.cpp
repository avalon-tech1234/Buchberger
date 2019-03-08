#include "PolynomialBuilders.h"
#include <cstdlib>

using namespace std;
using namespace my_algorithm;
using namespace my_IO;

int main()
{
	const string s1 = "x1";
	const string s2 = "2x1";
	const string s3 = "2x1^3";
	const string s4 = "2x1^3 +4";
	const string s5 = "2x1^3 +4x3";
	const string s6 = "2x1^3 +4x3   + 7";
	const string s7 = "2x1^3x4^2 +4x3   + 7";

	StringEquationSystemBuilder builder = StringEquationSystemBuilder(s7);
	Polynomial output;
	builder.inputPolynomial(output);
		

	system("pause");
	return 0;
}