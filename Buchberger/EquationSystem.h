#pragma once
#include "Polynomial.h"
#include <map>

namespace basic {


	class EquationSystem
	{
	private:
		std::map<std::string, int> var_dic; //������� ����������: ������ �������� - "�������" ��� ����������, ������ - "��� ����������� �������������"
		std::vector <Polynomial> polynomials;

		IArithmetic rules; // ����, �������� ����������� ������������

	public:

		// �������� ������������� ��������� ����������. 0 - ������������ ����������, 1 - ����������1, ���� ����� �������� ����������
		EquationSystem(int a) 
		{
			if (a == 0) rules = TraditionalArithmetic();
			else if (a == 1) rules = Arithmetic1();
			else throw std::runtime_error("attempt to use unknown arithmetic");
		}
		//EquationSystem(std::map<std::string, int> in_dic, std::vector <Polynomial> in_polynomials)  : var_dic(in_dic), polynomials(in_polynomials) {};
		~EquationSystem();

		void addPolynomial(Polynomial* p);

		// ������ ������������ :(
		std::map<std::string, int>* getVariablesDictionary() { return &var_dic; };

		 //�������� ������ ���������
		void remove_empty();

		// ������������� ����� �������. ������� �������� �� ������ �� ������
		// � ����� �� ����� ������ ������ "end"
		void read_from_console();

		// ������������� �� �����
		void read_from_file(std::string filename);


		std::string toString();


	};
}