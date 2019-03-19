#pragma once
#include <string>
#include <iostream>
#include "EnvironmentInitializer.h"

using namespace std;
using namespace basic;

namespace my_IO {
	// ввод полиномов из файла или через консоль
	void EnvironmentInitializer::initialize(EquationSystem* sys)
	{
		string s;
		cout << "Введите 1, если ввод данных должен происходить через консоль, или 2, если из файла. Затем нажмите Enter.. ";
		while (true)
		{
			getline(cin, s);
			if (s[0] == '1' || s[0] == '2') break;
			else cout << "Необходимо ввести 1 или 2.. ";
		}
		if (s[0] == '1')
		{
			cout << "Осуществляется ввод полиномов через консоль. \nВводите полиномы по одному на строке. Чтобы закончить ввод, введите пустую строку." << endl;
			sys->read_from_console();
		}
		else if (s[0] == '2')
		{
			cout << "Осуществляется ввод полиномов из файла input.txt" << endl;
			sys->read_from_file("C:\\Users\\Admin\\Documents\\Работа\\Buchberger\\Buchberger\\input.txt");
		}
	}

	// назначение арифметики для заданной системы уравнений, n задает арифмеитку (0 - традиционная арифметика, 1 - Arithmetic1 (см. Arothmetics.h). Если хотя бы один коэффициент не соответствует системе уравнений, произойдет ArithmeticException
	//void assignArithmetic(basic::EquationSystem* sys);

}