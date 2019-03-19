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
			getline(cin, cur); // читаем строку из консоли
			if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
			try {
				parser.inputPolynomial(*this, cur); // извлекаем из нее полином и добавляем его в САУ
			}
			catch (ParsingException& e)
			{
				cout << "Неверный ввод последнего полинома. При чтении символа " << e.where()<< " произошла ошибка: " << e.what() << endl;
				cout << "Введите полином корректно или нажмите Enter для окончания ввода" << endl;
				str_num--;
			}
			catch (exception& e)
			{
				cout << "Неверный ввод последнего полинома. Произошла ошибка " << e.what() << endl;
				cout << "Введите полином корректно или нажмите Enter для окончания ввода" << endl;
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
			getline(infile, cur); // читаем строку из файла
			if (cur == "end" || cur == "stop" || cur == "exit" || cur == "") break;
			try {
				parser.inputPolynomial(*this, cur); // извлекаем из нее полином и добавляем его в САУ
				cout << "Строка " << ++str_num << " успешно прочитана" << endl;
			}
			catch (ParsingException& e)
			{
				cout << "Неверный ввод полинома на строке " << str_num << ". При чтении символа " << e.where() << " произошла ошибка: " << e.what() << endl;
				break;
			}
			catch (exception& e)
			{
				cout << "Неверный ввод полинома на строке " << str_num << ". Произошла ошибка " << e.what() << endl;
				break;
			}
		}

		cout << "Ввод полиномов завершен. Прочитано " << str_num << " полиномов"<< endl;
	}


}