#pragma once
#include <string>
#include <iostream>
#include "EnvironmentInitializer.h"

using namespace std;
using namespace basic;

namespace my_IO {
	// ���� ��������� �� ����� ��� ����� �������
	void EnvironmentInitializer::initialize(EquationSystem* sys)
	{
		string s;
		cout << "������� 1, ���� ���� ������ ������ ����������� ����� �������, ��� 2, ���� �� �����. ����� ������� Enter.. ";
		while (true)
		{
			getline(cin, s);
			if (s[0] == '1' || s[0] == '2') break;
			else cout << "���������� ������ 1 ��� 2.. ";
		}
		if (s[0] == '1')
		{
			cout << "�������������� ���� ��������� ����� �������. \n������� �������� �� ������ �� ������. ����� ��������� ����, ������� ������ ������." << endl;
			sys->read_from_console();
		}
		else if (s[0] == '2')
		{
			cout << "�������������� ���� ��������� �� ����� input.txt" << endl;
			sys->read_from_file("C:\\Users\\Admin\\Documents\\������\\Buchberger\\Buchberger\\input.txt");
		}
	}

	// ���������� ���������� ��� �������� ������� ���������, n ������ ���������� (0 - ������������ ����������, 1 - Arithmetic1 (��. Arothmetics.h). ���� ���� �� ���� ����������� �� ������������� ������� ���������, ���������� ArithmeticException
	//void assignArithmetic(basic::EquationSystem* sys);

}