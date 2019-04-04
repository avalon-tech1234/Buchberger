#include "Environment.cpp"
#include <iostream>

using namespace std;
using namespace basic;

int main()
{
	//const string test_str = "2x1^3x4^2 +4x3   + 7";
	setlocale(0, "");


	try {
		cout << " ! ÏÐÎÃÐÀÌÌÀ ÍÀ×ÈÍÀÅÒ ÐÀÁÎÒÓ !" << endl << endl;
		Environment env;
		bool result = env.initialize_everything();

		if (!result) // åñëè îøèáîê íåò
			env.substitute();
		else cout << "Ïîäñòàíîâêà íå ïðîèçâåäåíà" << endl;
	}
	catch (exception& e)
	{
		cout << "Ïðîèçîøëà îøèáêà. Òåêñò îøèáêè: " << e.what() << endl;
	}

	cout << endl << " ! ÏÐÎÃÐÀÌÌÀ ÇÀÊÀÍ×ÈÂÀÅÒ ÐÀÁÎÒÓ !" << endl << endl;
	system("pause");
	return 0;
}