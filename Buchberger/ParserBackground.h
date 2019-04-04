#pragma once
#include "PolynomialBuilder.h"
#include "ParsingException.h"
#include "Utility.h"
#include "Grade.h"



namespace my_IO
{
	enum class AddMode
	{
		push_empty,
		puth_others
	};


	class ParserBackground : public PolynomialBilder
	{
	private:
		int state;
		std::string str; // ������������� ������
		char symb; // ������� ������
		std::string source;
		int state_saved; // ������ �������� state ��� ������ �����������
		int symb_place;
		const basic::IArithmetic* rules;
		std::map<std::string, int> dictionary;
		int base = 0;
		int first_free_num = 0;


	public:

		ParserBackground(std::string source, const basic::IArithmetic* rules, const std::map<std::string, int>& dictionary) : source(source), rules(rules), dictionary(dictionary) {}

		inline void to(int st)
		{
			str = symb;
			state = st;
		}

		inline void refresh()
		{
			char c = source[symb_place++];
			if (c < 0 || c > 122)
				throw ParsingException("������ ������������ ������", symb_place);
			symb = c;
		}

		inline SymbolTypes cur_type()
		{
			return what_type(symb);
		}
		inline SymbolTypes cur_coeff()
		{
			return what_coeff(symb);
		}

		inline void pause()
		{
			state_saved = state;
			state = 6;
		}
		inline void unpause()
		{
			state = state_saved;
		}

		/*
		�������� ������� ��������� ������. ��������� ��������:
		0 - ��������� ���������
		1 - ����������� ������� ������������
		2 - ����������� ������� �������� ����������
		3 - ����������� ��������� ������� �������
		4 - ����� ��������
		5 - ����������� ������� �������
		6 - ������� ����������� (����� [ � ])
		*/
		inline int show_state()
		{
			return state;
		}

		inline void read()
		{
			str += symb;
		}

		inline bool stop()
		{
			return state == 4;
		}

		// throws ParsingException if monomial coefficient is out of range
		inline void setCoeff(int a)
		{
			if (!rules->belongs(a))
				throw ParsingException("��� �������� �������� �������� �����������, �� ������������� ��������� ���������", symb_place);
			MonomialBuilder::setCoeff(a);
			to(2);
		}

		// throws ParsingException if monomial coefficient is out of range
		// �������� �������� � ����������� ��, ��� ��� ���� � ������
		inline void setCoeff()
		{
			if (!rules->belongs(std::stoi(str, nullptr)))
				throw ParsingException("��� �������� �������� �������� �����������, �� ������������� ��������� ���������", symb_place);
			MonomialBuilder::setCoeff(std::stoi(str, nullptr));
			to(2);
		}

		void go_wrong(std::string text)
		{
			throw ParsingException(text, symb_place);
		}

		void addMonomial(AddMode mode)
		{
			if (mode == AddMode::puth_others)
				PolynomialBilder::addMonomial(stoi(str, nullptr));
			if (mode == AddMode::push_empty)
				PolynomialBilder::addMonomial();
		}
		void addGrade(AddMode mode)
		{
			if (mode == AddMode::puth_others)
				MonomialBuilder::addGrade(basic::Grade(base, stoi(str, nullptr)));
			if (mode == AddMode::push_empty)
				MonomialBuilder::addGrade(basic::Grade(get_var_num(), 1));

		}
		int get_var_num()
		{
			int res;
			std::map<std::string, int>::iterator it;
			it = dictionary.find(str);
			if (it == dictionary.end())
			{
				res = first_free_num++;
				dictionary[str] = res;
			}
			else
				res = it->second;
			return res;
		}

		void setBase()
		{

			base = get_var_num();
		}

		const std::map<std::string, int>& getDictionary()
		{
			return dictionary;
		}

	};
}