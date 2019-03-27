#pragma once
#include <iostream>
#include "Environment.h"
#include "Writer.h"

using namespace std;
using namespace basic;

namespace my_IO {

	// ввод полиномов из файла или через консоль
	bool Environment::initialize_system(EquationSystem& sys, Arithmetics rules)
	{
		bool flag_result = false;
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
			flag_result = sys.read_yourself_from_file("../input_pol.txt", rules);
			break;
		}
		return flag_result;
	}

	// ввод значений переменных из файла. пока они не связаны ни с какой САУ
	bool Environment::initialize_variables(basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		cout << "Начинается чтение переменных из файла input_var.txt" << endl;
		//cout << "Разделителем целой и дробной части считается запятая" << endl;
		return var_set.read_yourself_from_file("../input_var.txt", rules);

	}

	bool Environment::initialize_environment(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		bool flag_result1 = initialize_system(sys, rules);
		bool flag_result2 = initialize_variables(var_set, rules);
		return flag_result1 || flag_result2; // если хоть в одном ошибка, возвращаем ошибку
	}

	bool Environment::substitute(basic::EquationSystem& sys, basic::VariablesMap& var_set, basic::Arithmetics rules)
	{
		bool flag_result = false;
		vector<double> result = sys.substitute(var_set, rules);
		Writer::writePolynomialValues(sys, result, "../input_pol.txt", "../output.txt");
		cout << "Набор значений переменных подставлен в полиномы. Результат подстановки записан в файл output.txt" << endl;
		return flag_result;
	}

}