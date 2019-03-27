#pragma once
#include "AppliedArithmetic.h"
#include <vector>
#include <string>
#include <map>


namespace basic
{
	
	struct Grade
	{
		int base; // ����� ����������-��������� �������
		int exp; // ���������� �������
	 Grade(int base, int exp) : base(base), exp(exp) {};
	 static bool compare_in_list(const Grade& g1, const Grade& g2)
	 {
		 return g1.base < g2.base;
	 }
	};
	


	typedef std::map<std::string, int> Dictionary; // ������� ����������

	class VariablesMap: public std::map<std::string, double> // ��� ����������, �������� - ��, ��� �������� �� ����
	{
	public:
		bool read_yourself_from_file(std::string filename, Arithmetics rules);
		void addVariable(std::string var_name, double var_num)
		{
			operator[](var_name) = var_num;
		}
	};


	// ��������� map. ������ �������� - ����� ���������� (�.�. �� "���������� ��������"), ������ �������� - �� ��������
	struct ValuesList : public std::map<int, double>
	{

	public:
		// ����� �������� AbsentValueException
		ValuesList(basic::Dictionary dic, basic::VariablesMap vars);

	};

}