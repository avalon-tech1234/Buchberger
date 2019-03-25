#pragma once
#include "AppliedArithmetic.h"
#include <vector>
#include <string>
#include <map>


namespace basic
{
	typedef std::map<std::string, int> Dictionary; // словарь переменных

	class VariablesMap: public std::map<std::string, double> // имя переменной, значение - то, что подается на вход
	{
	public:
		void read_yourself_from_file(std::string filename, Arithmetics rules);
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