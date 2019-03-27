#include "Writer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

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
			if (floor(result[i]) == result[i])
				out << cur << " = " << fixed << (int)result[i++] << endl;
			else
				out << cur << " = " << fixed << result[i++] << endl;
		}

		in.close();
		out.close();
	}
}