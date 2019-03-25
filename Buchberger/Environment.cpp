#pragma once
#include <iostream>
#include "Environment.h"
#include "Writer.h"

using namespace std;
using namespace basic;

namespace my_IO {

	// ввод полиномов из файла или через консоль
	void Environment::initialize_system(EquationSystem& sys, Arithmetics rules)
	{
		string s = "2";

		// тут можно сделать консольный ввод полиномов - для отладки
		/*
		cout << "Введите 1, если ввод данных должен происходить через консоль, или 2, если из файла. Затем нажмите Enter.. ";
		while (true)
		{
			getline(cin, s);
			if (s[0] == '1' || s[0] == '2') break;
			else cout << "Необходимо ввести 1 или 2.. ";
		}
		*/

		switch (s[0])
		{
		case '1':
			cout << "Осуществляется ввод полиномов через консоль. \nВводите полиномы по одному на строке. Чтобы закончить ввод, введите пустую строку." << endl;
			sys.read_yourself_from_console(rules);
			break;
		case '2':
			cout << "Осуществляется ввод полиномов из файла input.txt" << endl;
			sys.read_yourself_from_file("../input_pol.txt", rules);
			break;
		}
	}

	// ввод значений переменных из файла. пока они не связаны ни с какой САУ
	void Environment::initialize_variables(basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		cout << "Начинается чтение переменных из файла input_var.txt" << endl;
		cout << "Разделителем целой и дробной части считается запятая" << endl;
		var_set.read_yourself_from_file("../input_var.txt", rules);

	}

	void Environment::initialize_environment(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		initialize_system(sys, rules);
		initialize_variables(var_set, rules);
	}

	void Environment::substitute(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		vector<double> result = sys.substitute(var_set, rules);
		Writer::writePolynomialValues(sys, result, "../input_pol.txt", "../output.txt");
		cout << "Набор значений переменных подставлен в полиномы. Результат подстановки записан в файл output.txt";
	}

}