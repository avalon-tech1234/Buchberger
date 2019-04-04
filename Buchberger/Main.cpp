#include "Environment.cpp"
#include <iostream>

using namespace std;
using namespace basic;

int main()
{
	//const string test_str = "2x1^3x4^2 +4x3   + 7";
	setlocale(0, "");


	try {
		cout << " ! ��������� �������� ������ !" << endl << endl;
		Environment env;
		bool result = env.initialize_everything();

		if (!result) // ���� ������ ���
			env.substitute();
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