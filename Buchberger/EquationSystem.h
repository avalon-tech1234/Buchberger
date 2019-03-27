#pragma once
#include "Polynomial.h"

namespace basic {


	class EquationSystem
	{
	private:
		Dictionary var_dic; //словарь переменных: первое значение - "внешнее" имя переменной, второе - "для внутреннего использования"
		std::vector <Polynomial> polynomials;	

	public:

		EquationSystem() {}

		~EquationSystem();

		void addPolynomial(Polynomial* p);

		// TODO: переписать PolynomialInitializer::inputPolynomial() так, чтобы эта функция была не нужна
		Dictionary* getVariablesDictionary() { return &var_dic; };

		// инициализация через консоль. вводить полиномы по одному на строку
		// в конце на новой строке ввести "end"
		// не выкидывает ошибок - любой ввод корректный
		void read_yourself_from_console(basic::Arithmetics rules);

		// инициализация из файла
		bool read_yourself_from_file(std::string filename, basic::Arithmetics rules);

		std::vector<double> substitute(basic::VariablesMap, basic::Arithmetics);

		std::string toString();


	};
}