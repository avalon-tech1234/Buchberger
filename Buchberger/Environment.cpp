#pragma once
#include <iostream>
#include "Environment.h"
#include "Writer.h"

using namespace std;
using namespace basic;

namespace my_IO {

	// ���� ��������� �� ����� ��� ����� �������
	bool Environment::initialize_system(EquationSystem& sys, Arithmetics rules)
	{
		bool flag_result = false;
		string s = "2";

		// ��� ����� ������� ���������� ���� ��������� - ��� �������
		/*
		cout << "������� 1, ���� ���� ������ ������ ����������� ����� �������, ��� 2, ���� �� �����. ����� ������� Enter.. ";
		while (true)
		{
			getline(cin, s);
			if (s[0] == '1' || s[0] == '2') break;
			else cout << "���������� ������ 1 ��� 2.. ";
		}
		*/

		switch (s[0])
		{
		case '1':
			cout << "�������������� ���� ��������� ����� �������. \n������� �������� �� ������ �� ������. ����� ��������� ����, ������� ������ ������." << endl;
			sys.read_yourself_from_console(rules);
			break;
		case '2':
			cout << "�������������� ���� ��������� �� ����� input.txt" << endl;
			flag_result = sys.read_yourself_from_file("../input_pol.txt", rules);
			break;
		}
		return flag_result;
	}

	// ���� �������� ���������� �� �����. ���� ��� �� ������� �� � ����� ���
	bool Environment::initialize_variables(basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		cout << "���������� ������ ���������� �� ����� input_var.txt" << endl;
		//cout << "������������ ����� � ������� ����� ��������� �������" << endl;
		return var_set.read_yourself_from_file("../input_var.txt", rules);

	}

	bool Environment::initialize_environment(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		bool flag_result1 = initialize_system(sys, rules);
		bool flag_result2 = initialize_variables(var_set, rules);
		return flag_result1 || flag_result2; // ���� ���� � ����� ������, ���������� ������
	}

	bool Environment::substitute(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		bool flag_result = false;
		vector<double> result = sys.substitute(var_set, rules);
		Writer::writePolynomialValues(sys, result, "../input_pol.txt", "../output.txt");
		cout << "����� �������� ���������� ���������� � ��������. ��������� ����������� ������� � ���� output.txt" << endl;
		return flag_result;
	}

}