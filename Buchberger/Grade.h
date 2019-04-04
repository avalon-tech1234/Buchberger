#pragma once
#include "Arithmetics.h"
#include <vector>
#include <string>
#include <map>


namespace basic
{

	struct Grade
	{
		int base; // номер переменной-основания степени
		int exp; // показатель степени
		Grade(int base, int exp) : base(base), exp(exp) {};
		inline static bool compare_in_list(const Grade& g1, const Grade& g2)
		{
			return g1.base < g2.base;
		}
	};

}