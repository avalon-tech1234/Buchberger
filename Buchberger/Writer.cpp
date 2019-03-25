#include "Writer.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace my_IO 
{
	void Writer::writePolynomialValues(basic::EquationSystem& sys, std::vector<double> result, string input, string output)
	{
		ofstream out;
		out.open(output);

		ifstream in;
		in.open(input);

		string cur;
		int i = 0;

		while (getline(in, cur))
		{
			out << cur << " = " << result[i];
		}

		in.close();
		out.close();
	}
}