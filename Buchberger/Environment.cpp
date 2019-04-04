#pragma once
#include "Environment.h"
#include "stdafx.h"
#include "Reader.h"
#include "Writer.h"
#include "InitialisationFailedException.h"

using namespace std;
using namespace basic;
using namespace my_IO;

// ���� ��������� �� ����� ��� ����� �������
void Environment::initialize_system()
{
	string s = "2";

	// ��� ����� ������� ���������� ���� ���������
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
		Reader::read_system_from_console(system);
		break;
	case '2':
		Reader::read_system_from_file(system, path_input_pol);
		break;
	}
}

// ���� �������� ���������� �� �����. ���� ��� �� ������� �� � ����� ���
void Environment::initialize_variables()
{
	values = Reader::read_variables_from_file(system.getVariablesDictionary(), rules, path_input_var);
}

/*
bool Environment::initialize_environment(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::basic rules)
{
	bool flag_result1 = initialize_system(sys, rules);
	bool flag_result2 = initialize_variables(var_set, rules);
	return flag_result1 || flag_result2; // ���� ���� � ����� ������, ���������� ������
}
*/

void Environment::substitute()
{
	vector<double> result = system.substitute(values);
	Writer::writePolynomialValues(system, result, path_input_pol, path_output);
}

// quietly returns false if initialization successful, otherwise reports and throws false
bool Environment::initialize_everything()
{
	try
	{
		initialize_system();
		initialize_variables();
	}
	catch (InitialisationFailedException e)
	{
		cout << "�� ������� ���������� �������������: " << e.what() << endl;
		return true;
	}

	return false;
}
