#include "PolynomialInitializer.h"
#include "ParsingException.h"
#include <string>
#include <ctype.h>


using namespace basic;
using namespace std;

namespace my_IO {

	void PolynomialInitializer::inputPolynomial(EquationSystem & input, string source)
	{
		symb_place = 0;
		do
		{
			symb = source[symb_place++];

			if (symb < 0 || symb > 122) throw ParsingException("введен недопустимый символ", symb_place);

			if (!isempty())
			{
				switch (state)
				{
				case 0:
					if (issign() || isdig()) to_state(1);
					else if (isalph()) setMonomCoeff(1);
					else if (istrail()) to_state(4);
					else throw ParsingException("некорректное начало полинома", symb_place);
					break;
				case 1:
					if (isdig()) str += symb;
					else if (isalph()) setMonomCoeff(stoi(str, nullptr));
					else if (istrail()) pushFreeMember(stoi(str, nullptr));
					else throw ParsingException("некорректно введен коэффициент", symb_place);
					break;
				case 2:
					if (isdig()) str += symb;
					else if (issign() || istrail()) pushMonomial(get_var_num(input.getVariablesDictionary()), 1, istrail());
					else if (iscap()) setGradeBase(input.getVariablesDictionary());
					else throw ParsingException("некорректно введено им€ переменной", symb_place);
					break;
				case 3:
					if (isdig()) to_state(5);
					else throw ParsingException("некорректно введена степень", symb_place);
					break;
				case 5:
					if (isdig()) str += symb;
					else if (issign() || istrail()) pushMonomial(base, stoi(str, nullptr), istrail());
					else if (isalph()) setGrade(base, stoi(str, nullptr));
					else throw ParsingException("некорректно введена степень", symb_place);
					break;
				}
			}
		} while (state != 4);
		Polynomial p(monomials);
		input.addPolynomial(&p);
		cleanup();
	}

	// плюс или минус
	bool PolynomialInitializer::issign()
	{
		return symb == '+' || symb == '-';
	}

	// символ \0 - NULL - конец строки (завершает работу машины)
	bool PolynomialInitializer::istrail()
	{
		return symb == '\0';
	}

	// крышка (предвар€ет ввд степени)
	bool PolynomialInitializer::iscap()
	{
		return symb == '^';
	}

	// цифра
	bool PolynomialInitializer::isdig()
	{
		return isdigit(symb);
	}

	// буква
	bool PolynomialInitializer::isalph()
	{
		return isalpha(symb);
	}

	// пустой символ (пробел или табул€ци€)
	bool PolynomialInitializer::isempty()
	{
		return isblank(symb);
	}

	int PolynomialInitializer::get_var_num(std::map<std::string, int>* var_dic)
	{
		std::map<std::string, int>::iterator it = var_dic->find(str);
		if (it == var_dic->end())
		{
			(*var_dic)[str] = first_free_num;
			return first_free_num++;
		}
		else
			return it->second;
	}

	void PolynomialInitializer::to_state(int st)
	{
		str = symb;
		state = st;
	}

	void PolynomialInitializer::pushMonomial(int last_base, int last_exp, bool is_end)
	{
		grades.push_back(pair<int, int>(last_base, last_exp));
		monomials.push_back(Monomial(monom_coeff, grades));
		grades.clear();
		if (is_end) to_state(4);
		else to_state(1);
	}

	void PolynomialInitializer::pushFreeMember(int coeff)
	{
		monomials.push_back(Monomial(coeff, grades));
		to_state(4);
	}

	void PolynomialInitializer::setMonomCoeff(int a)
	{
		grades = vector<pair<int, int>>();
		monom_coeff = a;
		to_state(2);
	}

	void PolynomialInitializer::setGradeBase(std::map<std::string, int>* var_dic)
	{
		base = get_var_num(var_dic);
		to_state(3);
	}

	void PolynomialInitializer::setGrade(int base, int exp)
	{
		grades.push_back(pair<int, int>(base, exp));
		to_state(2);
	}

	void PolynomialInitializer::cleanup()
	{
		symb_place = 0;
		str = "";
		state = 0;

		vector<Monomial>().swap(monomials);
		std::vector<pair<int, int>>().swap(grades);
		monom_coeff = 0;
		base = 0;
	}

}