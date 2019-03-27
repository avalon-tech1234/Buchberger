#include "PolynomialInitializer.h"
#include "ParsingException.h"
#include "Utility.h"
#include <string>


using namespace basic;
using namespace std;

namespace my_IO {

	// TODO: добавить проверку на то, что в конце чтения все в порядке (нет несохраненной информации), иначе выкинуть ошибку
	void PolynomialInitializer::inputPolynomial(EquationSystem & input, string source, basic::Arithmetics rules)
	{
		int symb_place = 0;
		state = 0;
		int state_served; // хранит значение state при чтении комментария
		
		do
		{
			symb = source[symb_place++];

			if (symb < 0 || symb > 122) throw ParsingException("введен недопустимый символ", symb_place);

			if (!isempty(symb))
			{
				switch (state)
				{
				case 0:
					if (symb == '[')
					{
						state_served = state;
						state = 6;
					}
					else if (issign(symb) || isdig(symb)) to_state(1);
					else if (isalph(symb)) setMonomCoeff(symb_place, 1, rules);
					else if (istrail(symb)) to_state(4);
					else throw ParsingException("некорректное начало полинома", symb_place);
					break;
				case 1:
					if (symb == '[')
					{
						state_served = state;
						state = 6;
					}
					else if (isdig(symb)) str += symb;
					else if (isalph(symb))
					{
						if (str == "-") setMonomCoeff(symb_place, -1, rules);
						else if (str == "+") setMonomCoeff(symb_place, 1, rules);
						else setMonomCoeff(symb_place, stoi(str, nullptr), rules);
					}
					else if (istrail(symb)) pushFreeMember(stoi(str, nullptr));
					else throw ParsingException("некорректно введен коэффициент", symb_place);
					break;
				case 2:
					if (symb == '[')
					{
						state_served = state;
						state = 6;
					}
					else if (isdig(symb)) str += symb;
					else if (issign(symb) || istrail(symb)) pushMonomial(get_var_num(input.getVariablesDictionary()), 1, istrail(symb));
					else if (iscap(symb)) setGradeBase(input.getVariablesDictionary());
					else if (isalph(symb)) setGrade(get_var_num(input.getVariablesDictionary()), 1);
					else throw ParsingException("некорректно введено имя переменной", symb_place);
					break;
				case 3:
					if (symb == '[')
					{
						state_served = state;
						state = 6;
					}
					else if (isdig(symb)) to_state(5);
					else throw ParsingException("некорректно введена степень", symb_place);
					break;
				case 5:
					if (symb == '[')
					{
						state_served = state;
						state = 6;
					}
					else if (isdig(symb)) str += symb;
					else if (issign(symb) || istrail(symb)) pushMonomial(base, stoi(str, nullptr), istrail(symb));
					else if (isalph(symb)) setGrade(base, stoi(str, nullptr));
					else throw ParsingException("некорректно введена степень", symb_place);
					break;
				case 6:
					if (symb == ']') state = state_served;
					break;
				}
			}
		} while (state != 4);
		Polynomial p = monomials;
		input.addPolynomial(&p);
		cleanup();
	}

	int PolynomialInitializer::get_var_num(Dictionary* var_dic)
	{
		std::map<std::string, int>::iterator it = var_dic->find(str);
		if (it == var_dic->end())
		{
			(*var_dic)[str] = first_free_num;
			return first_free_num++;
		}
		else return it->second;
	}

	void PolynomialInitializer::to_state(int st)
	{
		str = symb;
		state = st;
	}

	void PolynomialInitializer::pushMonomial(int last_base, int last_exp, bool is_end)
	{
		grades.push_back(Grade(last_base, last_exp));
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

	// throws ParsingException if monomial coefficient is out of range
	void PolynomialInitializer::setMonomCoeff(int symb_place, int a, basic::Arithmetics rules)
	{
		if (!AppliedArithmetic::belongs(a, rules))
			throw ParsingException("При парсинге полинома встречен коэффициент, не принадлежащий заданному множеству", symb_place);
		grades = vector<Grade>();
		monom_coeff = a;
		to_state(2);
	}

	void PolynomialInitializer::setGradeBase(Dictionary* var_dic)
	{
		base = get_var_num(var_dic);
		to_state(3);
	}

	void PolynomialInitializer::setGrade(int base, int exp)
	{
		grades.push_back(Grade(base, exp));
		to_state(2);
	}

	void PolynomialInitializer::cleanup()
	{
		str = "";
		state = 0;

		vector<Monomial>().swap(monomials);
		std::vector<Grade>().swap(grades);
		monom_coeff = 0;
		base = 0;
	}

}