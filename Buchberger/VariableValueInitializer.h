#pragma once
#include "Smalls.h"


namespace my_IO
{
	class VariableValueInitializer
	{
	private:
		char symb; // ������� ������
		int symb_place; // ����� ��������������� �������
		int str_len; // ����� ������� ������
		std::string input; // �������������� ������
		std::string str; // ������������� ������



		std::string var_name;

	public:
		void inputVariableValue(basic::VariablesMap &, std::string source, basic::Arithmetics rules);
	};
}