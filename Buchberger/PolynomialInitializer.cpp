#include "PolynomialInitializer.h"
#include "ParsingException.h"
#include "Utility.h"
#include <string>


using namespace basic;
using namespace std;

namespace my_IO {

	void PolynomialInitializer::inputPolynomial(EquationSystem & input, string source, basic::Arithmetics rules)
	{
		//symb_place = 0;
		
		do
		{
			symb = source[symb_place++];

			if (symb < 0 || symb > 122) throw ParsingException("введен недопустимый символ", symb_place);

			if (!isempty(symb))
			{
				switch (state)
				{
				case 0:
					if (issign(symb) || isdig(symb)) to_state(1);
					else if (isalph(symb)) setMonomCoeff(1, rules);
					else if (istrail(symb)) to_state(4);
					else throw ParsingException("некорректное начало полинома", symb_place);
					break;
				case 1:
					if (isdig(symb)) str += symb;
					else if (isalph(symb)) setMonomCoeff(stoi(str, nullptr), rules);
					else if (istrail(symb)) pushFreeMember(stoi(str, nullptr));
					else throw ParsingException("некорректно введен коэффициент", symb_place);
					break;
				case 2:
					if (isdig(symb)) str += symb;
					else if (issign(symb) || istrail(symb)) pushMonomial(get_var_num(input.getVariablesDictionary()), 1, istrail(symb));
					else if (iscap(symb)) setGradeBase(input.getVariablesDictionary());
					else if (isalph(symb)) setGrade(get_var_num(input.getVariablesDictionary()), 1);
					else throw ParsingException("некорректно введено имя переменной", symb_place);
					break;
				case 3:
					if (isdig(symb)) to_state(5);
					else throw ParsingException("некорректно введена степень", symb_place);
					break;
				case 5:
					if (isdig(symb)) str += symb;
					else if (issign(symb) || istrail(symb)) pushMonomial(base, stoi(str, nullptr), istrail(symb));
					else if (isalph(symb)) setGrade(base, stoi(str, nullptr));
					else throw ParsingException("некорректно введена степень", symb_place);
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

	// throws ParsingException if monomial is out of range
	void PolynomialInitializer::setMonomCoeff(int a, basic::Arithmetics rules)
	{
		if (!AppliedArithmetic::belongs(a, rules))
			throw ParsingException("При парсинге полинома встречен коэффициент, не принадлежащий заданному множеству", symb_place);
		grades = vector<pair<int, int>>();
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