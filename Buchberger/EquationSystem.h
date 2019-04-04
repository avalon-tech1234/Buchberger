#pragma once
#include "Polynomial.h"

namespace basic {


	class EquationSystem
	{
	const basic::IArithmetic* rules;
	private:
		std::map<std::string, int> var_dic; //словарь переменных: первое значение - "внешнее" имя переменной, второе - "для внутреннего использования"
		std::vector <Polynomial> polynomials;	

	public:

		EquationSystem(basic::IArithmetic* rules): rules(rules) {}

		~EquationSystem();

		void addPolynomial(Polynomial* p);

		const std::map<std::string, int>& getVariablesDictionary()
		{
			return var_dic; 
		};

		void setVariablesDictionary(const std::map<std::string, int>& in)
		{
			var_dic = in;
		}

		std::vector<double> substitute(const std::vector<double> values);

		std::string toString();

		const basic::IArithmetic* getRules() const
		{
			return rules;
		}

	};
}