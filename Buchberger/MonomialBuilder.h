#pragma once
#include <vector>
#include "Monomial.h"

// �����, ������������ ��� ���������� �������� ����� � ����������. ������������ ��� ���� ��� ������������ ������� PolynomialBuilder, � �� ��� ��������������� � Parser

namespace my_IO
{
	class MonomialBuilder
	{
	private:
		int monom_coeff; // ����������� ��� �������� ������
		std::vector<basic::Grade> grades; // ������� ������
		basic::Monomial mon;
	protected:
		void clean()
		{
			std::vector<basic::Grade>().swap(grades);
			monom_coeff = 0;
		}

		virtual const basic::Monomial& createMonomial()
		{
			return createMonomial(monom_coeff, grades);
		}
		virtual const basic::Monomial& createMonomial(int mk, std::vector<basic::Grade>& gr = std::vector<basic::Grade>())
		{
			mon = basic::Monomial(mk, gr);
			clean();
			return mon;
		}


	public:
		void setCoeff(int coeff)
		{
			monom_coeff = coeff;
		}
		virtual void addGrade(basic::Grade grade)
		{
			grades.push_back(grade);
		}
	};


}
