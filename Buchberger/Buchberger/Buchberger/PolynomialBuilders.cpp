#include "PolynomialBuilders.h"
#include <string>
#include <iostream>
#include <ctype.h>


using namespace my_algorithm;
using namespace std;

namespace my_IO {

	void IEquationSystemBuilder::inputPolynomial(Polynomial & input)
	{
		do
		{
			get_new_symb();

			if (!isempty())
			{
				switch (state)
				{
				case 0:
					if (issign() || isdig()) to_state(1);
					else if (isalph()) setMonomCoeff(1);
					else if (istrail()) to_state(4);
					else throw new invalid_argument("Некорректное начало полинома");
					break;
				case 1:
					if (isdig()) str += symb;
					else if (isalph()) setMonomCoeff(stoi(str, nullptr));
					else if (istrail()) pushFreeMember(stoi(str, nullptr));
					else throw new invalid_argument("Некорректно введен коэффициент");
					break;
				case 2:
					if (isdig()) str += symb;
					else if (issign() || istrail()) pushMonomial(get_var_num(), 1, istrail());
					else if (iscap()) setGradeBase();
					else throw new invalid_argument("Некорректно введено имя переменной");
					break;
				case 3:
					if (isdig()) to_state(5);
					else throw new invalid_argument("Некорректно введена степень");
					break;
				case 5:
					if (isdig()) str += symb;
					else if (issign() || istrail()) pushMonomial(base, stoi(str, nullptr), istrail());
					else if (isalph()) setGrade(base, stoi(str, nullptr));
					else throw new invalid_argument("Некорректно введена степень");
					break;
				}
			}
		} while (state != 4);

		std::vector<pair<int, int>>().swap(grades);
		input = Polynomial(monomials);
	}

	// плюс или минус
	bool IEquationSystemBuilder::issign()
	{
		return symb == '+' || symb == '-';
	}

	// конец строки или конец файла (завершает работу Машины)
	bool IEquationSystemBuilder::istrail()
	{
		return symb == '\r' || symb == '\n';
	}

	// крышка (предваряет ввд степени)
	bool IEquationSystemBuilder::iscap()
	{
		return symb == '^';
	}

	// цифра
	bool IEquationSystemBuilder::isdig()
	{
		return isdigit(symb);
	}

	// буква
	bool IEquationSystemBuilder::isalph()
	{
		return isalpha(symb);
	}

	// пустой символ (пробел или табуляция)
	bool IEquationSystemBuilder::isempty()
	{
		return isblank(symb);
	}

	int IEquationSystemBuilder::get_var_num()
	{
		std::map<std::string, int>::iterator it = var_dic.find(str);
		if (it == var_dic.end())
		{
			var_dic[str] = first_free_num;
			return first_free_num++;
		}
		else
			return it->second;
	}

	void IEquationSystemBuilder::to_state(int st)
	{
		str = symb;
		state = st;
	}

	void IEquationSystemBuilder::pushMonomial(int last_base, int last_exp, bool is_end)
	{
		grades.push_back(pair<int, int>(last_base, last_exp));
		monomials.push_back(Monomial(monom_coeff, grades));
		grades.clear();
		if (is_end) to_state(4);
		else to_state(1);
	}

	void IEquationSystemBuilder::pushFreeMember(int coeff)
	{
		monomials.push_back(Monomial(coeff, grades));
		to_state(4);
	}

	void IEquationSystemBuilder::setMonomCoeff(int a)
	{
		grades = vector<pair<int, int>>();
		monom_coeff = a;
		to_state(2);
	}

	void IEquationSystemBuilder::setGradeBase()
	{
		base = get_var_num();
		to_state(3);
	}

	void IEquationSystemBuilder::setGrade(int base, int exp)
	{
		grades.push_back(pair<int, int>(base, exp));
		to_state(2);
	}


	void ConsoleEquationSystemBuilder::get_new_symb()
	{
		std::cin.get(symb);
	}

}