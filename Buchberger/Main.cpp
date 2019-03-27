#include "PolynomialInitializer.h"
#include "Environment.cpp"
#include <cstdlib>

using namespace std;
using namespace basic;
using namespace my_IO;


int main()
{
	//const string test_str = "2x1^3x4^2 +4x3   + 7";
	setlocale(0, "");


	try {
		cout << " ! ��������� �������� ������ !" << endl << endl;
		EquationSystem sys;
		VariablesMap vars;
		Arithmetics rules = Arithmetics::ARITHMETIC1;
		bool not_success = Environment::initialize_environment(sys, vars, rules);
		if (!not_success) // ���� ������ ���
			Environment::substitute(sys, vars, rules);
		else cout << "����������� �� �����������" << endl;
	}
	catch (exception& e)
	{
		cout << "��������� ������. ����� ������: " << e.what() << endl;
	}

	cout << endl << " ! ��������� ����������� ������ !" << endl << endl;
	system("pause");
	return 0;
}