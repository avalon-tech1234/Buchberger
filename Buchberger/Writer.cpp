#include "Writer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;
using namespace basic;

namespace my_IO
{
	void Writer::writePolynomialValues(const EquationSystem& sys, const std::vector<double>& result, string input, string output)
	{
		cout << "Набор значений переменных подставлен в полиномы. Результат подстановки записан в файл " <<output<< endl;

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