#pragma once
#include <string>

namespace basic
{
	class InitialisationFailedException : public std::exception
	{
	protected:
		std::string msg; // текст ошибки

	public:

		explicit InitialisationFailedException(const std::string& message) : msg(message) {}

		explicit InitialisationFailedException() {};

		const char* what() const throw () { return msg.c_str(); }

	};
}
