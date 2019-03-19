#pragma once
#include <string>

namespace basic
{


	class ArithmeticException : public std::exception
	{

	protected:
		std::string msg; // текст ошибки

	public:

		explicit ArithmeticException(const std::string& message) : msg(message) {}

		explicit ArithmeticException() {};

		const char* what() const throw () { return msg.c_str(); }



	};
}