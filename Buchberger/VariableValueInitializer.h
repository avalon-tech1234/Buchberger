#pragma once
#include "Smalls.h"


namespace my_IO
{
	class VariableValueInitializer
	{
	private:
		char symb; // текущий символ
		int symb_place; // номер обрабатываемого символа
		int str_len; // длина входной строки
		std::string input; // обрабатываемая строка
		std::string str; // накапливаемая строка



		std::string var_name;

	public:
		void inputVariableValue(basic::VariablesMap &, std::string source, basic::Arithmetics rules);
	};
}