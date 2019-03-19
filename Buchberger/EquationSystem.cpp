#include "EquationSystem.h"
#include "PolynomialInitializer.h"
#include "ParsingException.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>



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

	void EquationSystem::read_from_console()
	{
		size_t str_num = 1;
		PolynomialInitializer parser;
		string cur;
		setlocale(0, "");

		while (true)
		{
			cout << (str_num++) << " > ";
			getline(cin, cur); // ������ ������ �� �������
			if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
			try {
				parser.inputPolynomial(*this, cur); // ��������� �� ��� ������� � ��������� ��� � ���
			}
			catch (ParsingException& e)
			{
				cout << "�������� ���� ���������� ��������. ��� ������ ������� " << e.where()<< " ��������� ������: " << e.what() << endl;
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
	}

	void EquationSystem::read_from_file(string filename)
	{
		size_t str_num = 0;
		size_t success_count = 0;
		size_t fail_count = 0;
		PolynomialInitializer parser;
		string cur;

		ifstream infile(filename);


		while (true)
		{
			getline(infile, cur); // ������ ������ �� �����
			if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
			try {
				parser.inputPolynomial(*this, cur); // ��������� �� ��� ������� � ��������� ��� � ���
				cout << "������ " << ++str_num << " ������� ���������" << endl;
			}
			catch (ParsingException& e)
			{
				cout << "�������� ���� �������� �� ������ " << str_num << ". ��� ������ ������� " << e.where() << " ��������� ������: " << e.what() << endl;
				break;
			}
			catch (exception& e)
			{
				cout << "�������� ���� �������� �� ������ " << str_num << ". ��������� ������ " << e.what() << endl;
				break;
			}
		}

		cout << "���� ��������� ��������. ��������� " << str_num << " ���������"<< endl;
	}


}