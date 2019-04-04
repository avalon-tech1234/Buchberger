#include "Reader.h"
#include "ParsingException.h"
#include "InitialisationFailedException.h"
#include "AbsentVariableException.h"
#include <fstream>
#include <iostream>

using namespace basic;
using namespace std;

namespace my_IO
{

	void Reader::read_system_from_console(EquationSystem& es)
	{
		cout << "�������������� ���� ��������� ����� �������. \n������� �������� �� ������ �� ������. ����� ��������� ����, ������� ������ ������." << endl;

		size_t str_num = 1;
		string cur;
		setlocale(0, "");

		while (true)
		{
			cout << (str_num++) << " > ";
			getline(cin, cur);
			if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
			try {
				Parser::inputPolynomial(es, cur);
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

	void Reader::read_system_from_file(EquationSystem& es, const string filename)
	{
		cout << "�������������� ���� ��������� �� ����� " << filename << endl;

		size_t str_num = 0;
		string cur;
		ifstream infile(filename);

		while (getline(infile, cur))
		{
			try {
				if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
				Parser::inputPolynomial(es, cur);
				cout << "   ������ " << ++str_num << " ������� ���������" << endl;
			}

			catch (ParsingException& e)
			{
				infile.close();
				string info = "�������� ���� �������� �� ������ " + to_string(str_num) + ".��� ������ ������� " + to_string(e.where()) + " ��������� ������ : " + e.what();
				throw InitialisationFailedException(info);
			}
			catch (exception& e)
			{
				infile.close();
				string info = "�������� ���� �������� �� ������ " + to_string(str_num) + ". ��������� ������ " + e.what();
				throw InitialisationFailedException(info);
			}
		}
		infile.close();
		cout << "���� ��������� ��������. ��������� " << str_num << " ���������" << endl;
	}

	vector<double> Reader::read_variables_from_file(const std::map<std::string, int>& variables_to_read, const basic::IArithmetic* rules, string filename)
	{
		cout << "���������� ������ ���������� �� ����� " << filename << endl;


		size_t str_num = 0;
		string cur;
		ifstream infile(filename);
		std::map<string, int>::const_iterator it;
		size_t n = variables_to_read.size();
		vector<double> result(n);
		vector<pair<string, bool>> valid(n);

		for (it = variables_to_read.begin(); it != variables_to_read.end(); it++)
		{
			valid[it->second] = pair<string, int>(it->first, false);
		}


		try {
			while (getline(infile, cur))
			{
				if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;

				pair<string, double> res = Parser::inputVariableValue(rules, cur);
				it = variables_to_read.find(res.first);
				if (it != variables_to_read.end())
				{
					result[it->second] = res.second;
					valid[it->second].second = true;
					cout << "   �������� ���������� " << res.first << " ������� ��������� �� ������ " << ++str_num << endl;
				}
			}

			for (size_t i = 0; i < n; i++)
			{
				if (!valid[i].second) throw AbsentVariableException("", valid[i].first);
			}

		infile.close();
		cout << "���� �������� ���������� ��������. ��������� " << str_num << " �����" << endl;
		return result;
		}
		catch (ParsingException& e)
		{
			infile.close();

			string info = "�������� ���� �������� �� ������ " + to_string(str_num) + ". ��������� ������ " + e.what();
			throw InitialisationFailedException(info);
		}
		catch (AbsentVariableException& e)
		{
			infile.close();

			string info = "�� ������� ������ ����������� �������� ���������� " + e.what_variable();
			throw InitialisationFailedException(info);
		}
	}


}