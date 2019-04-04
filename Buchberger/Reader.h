#pragma once
#include "EquationSystem.h"
#include "Parser.h"



namespace my_IO {



	class Reader
	{


	public:
		// ������������� ����� �������. ������� �������� �� ������ �� ������
		// � ����� �� ����� ������ ������ "end"
		// �� ���������� ������ - ����� ���� ����������
		static void read_system_from_console(basic::EquationSystem& es);


		// ������������� �� �����
		static void read_system_from_file(basic::EquationSystem& es, std::string filename);

		static std::vector<double> read_variables_from_file(const std::map<std::string, int>& variables_to_read, const basic::IArithmetic* rules, std::string filename);
		
	};

}