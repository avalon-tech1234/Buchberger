#include "PolynomialInitializer.h"
#include "EnvironmentInitializer.cpp"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace basic;
using namespace my_IO;


int main()
{
	//const string test_str = "2x1^3x4^2 +4x3   + 7";
	setlocale(0, "");

	try {
		EquationSystem sys(1); // ������� ������� ���������

		EnvironmentInitializer init;
		init.initialize(&sys); // TODO: �������� �������� �� ��, ��� ������������ ��� ������� ����������� ����
	}
	catch (exception& e)
	{
		cout << "��������� ������. ����� ������: " << e.what() << endl;
	}



	system("pause");
	return 0;
}