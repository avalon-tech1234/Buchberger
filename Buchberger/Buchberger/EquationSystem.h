#pragma once
#include "Polynomial.h"
#include <map>

namespace my_algorithm {

	class EquationSystem
	{
	private:
		std::map<int, int> var_dic; //������� ����������: ������ �������� - ���������� ����� ����������, ������ - �������
		std::vector <my_algorithm::Polynomial> polynomials;

	public:
		EquationSystem() {};
		EquationSystem(std::map<int, int> in_dic, std::vector <my_algorithm::Polynomial> in_polynomials)  : var_dic(in_dic), polynomials(in_polynomials) {};
		~EquationSystem()
		{
			delete &var_dic;
			delete &polynomials;
		}

		void remove_empty(); //�������� ������ ���������


	};
}