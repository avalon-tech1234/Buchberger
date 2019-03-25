#pragma once
#include <string>

namespace basic
{
	class AbsentVariableException : public std::exception
	{
	protected:
		std::string msg; // ����� ������
		std::string var_name; // ��� ����������, ������� ����������� �� ������� ������

	public:

		explicit AbsentVariableException(const std::string& message, const std::string& variable_name) : msg(message), var_name(variable_name) {}

		explicit AbsentVariableException() {};

		const char* what() const throw () { return msg.c_str(); }

		const std::string what_variable() const throw () 
		{ return var_name.c_str(); }
	};
}
