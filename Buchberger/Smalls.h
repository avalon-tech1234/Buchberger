#pragma once
#include "AppliedArithmetic.h"
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
	 static bool compare_in_list(const Grade& g1, const Grade& g2)
	 {
		 return g1.base < g2.base;
	 }
	};
	


	typedef std::map<std::string, int> Dictionary; // словарь переменных

	class VariablesMap: public std::map<std::string, double> // имя переменной, значение - то, что подается на вход
	{
	public:
		bool read_yourself_from_file(std::string filename, Arithmetics rules);
		void addVariable(std::string var_name, double var_num)
		{
			operator[](var_name) = var_num;
		}
	};


	// наследник map. первое значение - номер переменной (т.е. ее "внутреннее название"), второе значение - ее значение
	struct ValuesList : public std::map<int, double>
	{

	public:
		// может выкинуть AbsentValueException
		ValuesList(basic::Dictionary dic, basic::VariablesMap vars);

	};

}