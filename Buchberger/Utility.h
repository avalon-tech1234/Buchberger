#pragma once
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>


namespace my_IO
{

	enum class SymbolTypes
	{
		unknown,
		sign,
		cap,
		digit,
		letter,
		empty,
		trail,
		open_comment,
		close_comment,

		// доп. значения
		plus,
		minus
	};

	inline SymbolTypes what_type(char symb)
	{
		if (symb == '+' || symb == '-') return SymbolTypes::sign;
		if (symb == '\0') return SymbolTypes::trail;
		if (symb == '^') return SymbolTypes::cap;
		if (isdigit(symb) != 0) return SymbolTypes::digit;
		if (isalpha(symb) != 0) return SymbolTypes::letter;
		if (isblank(symb) != 0) return SymbolTypes::empty;
		if (symb == '[') return SymbolTypes::open_comment;
		if (symb == ']') return SymbolTypes::close_comment;
		return SymbolTypes::unknown;
	}

	inline SymbolTypes what_coeff(char symb)
	{
		if (symb == '+') return SymbolTypes::plus;
		if (symb == '-') return SymbolTypes::minus;
		return SymbolTypes::digit;
	}

	// trim from start (in place)
	inline void ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
			return !std::isspace(ch);
		}));
	}

	// trim from end (in place)
	inline void rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), s.end());
	}

	// trim from both ends (in place)
	inline void trim(std::string &s) {
		ltrim(s);
		rtrim(s);
	}

	// trim from start (copying)
	static inline std::string ltrim_copy(std::string s) {
		ltrim(s);
		return s;
	}

	// trim from end (copying)
	static inline std::string rtrim_copy(std::string s) {
		rtrim(s);
		return s;
	}

	// trim from both ends (copying)
	static inline std::string trim_copy(std::string s) {
		trim(s);
		return s;
	}

}