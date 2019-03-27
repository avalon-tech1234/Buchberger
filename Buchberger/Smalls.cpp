#include "Smalls.h"
#include "VariableValueInitializer.h"
#include "ParsingException.h"
#include "AbsentVariableException.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace my_IO;

namespace basic
{

	// �������� � ������ ��� ���������� �� �������, �������� ������� ������� � ������ ��������. ���� ����� �� �����, state=0, ����� 1
	ValuesList::ValuesList(Dictionary dic, VariablesMap vars)
	{
		Dictionary::iterator cur;
		Dictionary::iterator end = dic.end();
		VariablesMap::iterator var_it;
		for (cur = dic.begin(); cur != end; ++cur)
		{
			var_it = vars.find(cur->first);
			if (var_it == vars.end()) throw AbsentVariableException("� ������ ������� ������ ����������� ����������. ����������� �� ����� ���� ������������", cur->first);
			else operator[](cur->second) = var_it->second;
		}
	}


	bool VariablesMap::read_yourself_from_file(string filename, Arithmetics rules)
	{
		bool flag_result = false;

		size_t str_num = 0;
		VariableValueInitializer parser;
		string cur;
		ifstream infile(filename);

		try {
			while (getline(infile, cur))
			{
				if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
				parser.inputVariableValue(*this, cur, rules);
				cout << "   ������ " << ++str_num << " ������� ���������" << endl;
			}
		}
		catch (exception& e)
		{
			cout << "�������� ���� �������� �� ������ " << str_num << ". ��������� ������ " << e.what() << endl;
			flag_result = true;
		}

		infile.close();
		cout << "���� �������� ���������� ��������. ��������� " << str_num << " �����" << endl;
		return flag_result;

	}
}