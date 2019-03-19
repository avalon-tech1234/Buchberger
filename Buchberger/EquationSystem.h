#pragma once
#include "Polynomial.h"
#include <map>

namespace basic {


	class EquationSystem
	{
	private:
		std::map<std::string, int> var_dic; //словарь переменных: первое значение - "внешнее" им€ переменной, второе - "дл€ внутреннего использовани€"
		std::vector <Polynomial> polynomials;

		IArithmetic rules; // поле, которому принадлежат коэффициенты

	public:

		// параметр соответствует выбранной арифметике. 0 - традиционна€ арифметика, 1 - јрифметика1, иное число вызывает исключение
		EquationSystem(int a) 
		{
			if (a == 0) rules = TraditionalArithmetic();
			else if (a == 1) rules = Arithmetic1();
			else throw std::runtime_error("attempt to use unknown arithmetic");
		}
		//EquationSystem(std::map<std::string, int> in_dic, std::vector <Polynomial> in_polynomials)  : var_dic(in_dic), polynomials(in_polynomials) {};
		~EquationSystem();

		void addPolynomial(Polynomial* p);

		// плоха€ инкапсул€ци€ :(
		std::map<std::string, int>* getVariablesDictionary() { return &var_dic; };

		 //удаление пустых полиномов
		void remove_empty();

		// инициализаци€ через консоль. вводить полиномы по одному на строку
		// в конце на новой строке ввести "end"
		void read_from_console();

		// инициализаци€ из файла
		void read_from_file(std::string filename);


		std::string toString();


	};
}