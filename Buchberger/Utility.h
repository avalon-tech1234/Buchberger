#pragma once
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>


namespace my_IO
{

	// ���� ��� �����
	inline bool issign(char symb)
	{
		return symb == '+' || symb == '-';
	}

	// ������ \0 - NULL - ����� ������ (��������� ������ ������)
	inline bool istrail(char symb)
	{
		return symb == '\0';
	}

	// ������ (���������� ��� �������)
	inline bool iscap(char symb)
	{
		return symb == '^';
	}

	// �����
	inline bool isdig(char symb)
	{
		return isdigit(symb);
	}

	// �����
	inline bool isalph(char symb)
	{
		return isalpha(symb);
	}

	// ������ ������ (������ ��� ���������)
	inline bool isempty(char symb)
	{
		return isblank(symb);
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