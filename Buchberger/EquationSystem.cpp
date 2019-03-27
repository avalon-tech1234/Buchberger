#include "EquationSystem.h"
#include "PolynomialInitializer.h"
#include "ParsingException.h"
#include <iostream>
#include <fstream>

using namespace my_IO;
using namespace std;

namespace basic {


	EquationSystem::~EquationSystem()
	{
		map<string, int>().swap(var_dic);
		vector<Polynomial>().swap(polynomials);
	}

	void EquationSystem::addPolynomial(Polynomial * p)
	{
		polynomials.push_back(*p);
	}

	void EquationSystem::read_yourself_from_console(Arithmetics rules)
	{
		size_t str_num = 1;
		PolynomialInitializer parser;
		string cur;
		setlocale(0, "");

		while (true)
		{
			cout << (str_num++) << " > ";
			getline(cin, cur);
			if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
			try {
				parser.inputPolynomial(*this, cur, rules);
			}
			catch (ParsingException& e)
			{
				cout << "�������� ���� ���������� ��������. ��� ������ ������� " << e.where() << " ��������� ������: " << e.what() << endl;
				cout << "������� ������� ��������� ��� ������� Enter ��� ��������� �����" << endl;
				str_num--;
			}
			catch (exception& e)
			{
				cout << "�������� ���� ���������� ��������. ��������� ������ " << e.what() << endl;
				cout << "������� ������� ��������� ��� ������� Enter ��� ��������� �����" << endl;
				str_num--;
			}
		}
		cout << "���� ��������� ��������" << endl;

	}

	bool EquationSystem::read_yourself_from_file(string filename, Arithmetics rules)
	{
		bool flag_result = false;

		size_t str_num = 0;
		PolynomialInitializer parser;
		string cur;
		ifstream infile(filename);

		try {
			while (getline(infile, cur))
			{
				if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
				parser.inputPolynomial(*this, cur, rules);
				cout << "   ������ " << ++str_num << " ������� ���������" << endl;
			}
		}
		catch (ParsingException& e)
		{
			cout << "�������� ���� �������� �� ������ " << str_num << ". ��� ������ ������� " << e.where() << " ��������� ������: " << e.what() << endl;
			flag_result = true;
		}
		catch (exception& e)
		{
			cout << "�������� ���� �������� �� ������ " << str_num << ". ��������� ������ " << e.what() << endl;
			flag_result = true;
		}

		infile.close();
		cout << "���� ��������� ��������. ��������� " << str_num << " ���������" << endl;
		return flag_result;
	}

	std::vector<double> EquationSystem::substitute(VariablesMap set, Arithmetics rules)
	{
		ValuesList list = ValuesList(var_dic, set);
		vector<double> values;
		size_t s = polynomials.size();
		for (size_t i = 0; i < s; i++)
		{
			values.push_back(polynomials[i].substitute(list, rules));
		}
		return values;
	}

}