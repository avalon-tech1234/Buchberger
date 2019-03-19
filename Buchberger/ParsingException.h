#pragma once
#include <string>

namespace my_IO
{


	class ParsingException : public std::exception
	{

	protected:
		std::string msg; // ����� ������
		size_t symb_num; // ����� �������, �� ������� �������� ������

	public:

		explicit ParsingException(const std::string& message, const size_t symbol_number) : msg(message), symb_num(symbol_number) {}

		explicit ParsingException() {};

		const char* what() const throw () { return msg.c_str(); }

		const size_t where() const throw () { return symb_num; }


	};
}