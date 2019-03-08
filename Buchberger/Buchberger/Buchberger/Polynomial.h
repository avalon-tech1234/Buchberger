#pragma once
#include <vector>


namespace my_algorithm {

	class Monomial
	{
	private:
		int coeff; //коэффициент при мономе
		std::vector< std::pair<int, int> > grades;

	public:
		Monomial(int coeff, std::vector< std::pair<int, int> > grades);
		Monomial(const Monomial &m) : grades(m.grades), coeff(m.coeff) {};
		Monomial() {};
		~Monomial()
		{
			std::vector<std::pair<int, int>>().swap(grades);
		}
		//byte compareTo(Monomial other);
	};

	class Polynomial
	{
	private:
		std::vector <my_algorithm::Monomial> monomials;
		my_algorithm::Monomial leadingMonomial;

		void refreshLeadingMonomial();

	public:
		Polynomial(std::vector <my_algorithm::Monomial> in_monomials): monomials(in_monomials) {};
		Polynomial() {};
		~Polynomial()
		{
			std::vector<my_algorithm::Monomial>().swap(monomials);
		}

		void remove_empty(); //удаление пустых мономов
		my_algorithm::Monomial getLeadingMonomial();

	};
}

