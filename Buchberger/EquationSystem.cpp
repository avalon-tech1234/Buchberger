#include "EquationSystem.h"
#include <iostream>

using namespace std;
using namespace basic;

namespace basic {


	EquationSystem::~EquationSystem()
	{
		map<string, int>().swap(var_dic);
		vector<Polynomial>().swap(polynomials);
	}

	void EquationSystem::addPolynomial(Polynomial * p)
	{
		polynomials.push_back(*p);
	}

	std::vector<double> EquationSystem::substitute(const vector<double> values)
	{
		vector<double> result;
		result.reserve(polynomials.size());
		size_t s = polynomials.size();
		for (size_t i = 0; i < s; i++)
		{
			result.push_back(polynomials[i].substitute(values, rules));
			cout << "   Найдено значение полинома " << (i + 1) << " из " << s << endl;
		}
		return result;
	}

}