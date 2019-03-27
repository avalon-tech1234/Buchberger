#pragma once
#include "Polynomial.h"

namespace basic {


	class EquationSystem
	{
	private:
		Dictionary var_dic; //������� ����������: ������ �������� - "�������" ��� ����������, ������ - "��� ����������� �������������"
		std::vector <Polynomial> polynomials;	

	public:

		EquationSystem() {}

		~EquationSystem();

		void addPolynomial(Polynomial* p);

		// TODO: ���������� PolynomialInitializer::inputPolynomial() ���, ����� ��� ������� ���� �� �����
		Dictionary* getVariablesDictionary() { return &var_dic; };

		// ������������� ����� �������. ������� �������� �� ������ �� ������
		// � ����� �� ����� ������ ������ "end"
		// �� ���������� ������ - ����� ���� ����������
		void read_yourself_from_console(basic::Arithmetics rules);

		// ������������� �� �����
		bool read_yourself_from_file(std::string filename, basic::Arithmetics rules);

		std::vector<double> substitute(basic::VariablesMap, basic::Arithmetics);

		std::string toString();


	};
}