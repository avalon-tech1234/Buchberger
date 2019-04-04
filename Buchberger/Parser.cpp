#include "Parser.h"
#include "ParserBackground.h"


using namespace basic;
using namespace std;

namespace my_IO {

	// throws ParsingException if monomial coefficient is out of range
	void Parser::inputPolynomial(EquationSystem & input, string source)
	{

		ParserBackground engine(source, input.getRules(), input.getVariablesDictionary());

		do
		{
			engine.refresh();
			SymbolTypes type = engine.cur_type();
			SymbolTypes coeff = engine.cur_coeff();

			if (type == SymbolTypes::empty) continue;
			if (type == SymbolTypes::open_comment)
			{
				engine.pause();
				continue;
			}

			switch (engine.show_state())
			{
			case 0:
				switch (type) {
				case SymbolTypes::sign:
				case SymbolTypes::digit:
					engine.to(1); break;
				case SymbolTypes::letter:
					engine.setCoeff(1);
					engine.to(2);
					break;
				case SymbolTypes::trail:
					engine.to(4); break;
				default:
					engine.go_wrong("некорректное начало полинома");
				}
				break;
			case 1:
				switch (type) {
				case SymbolTypes::digit:
					engine.read(); break;
				case SymbolTypes::letter:
					switch (coeff)
					{
					case SymbolTypes::plus:
						engine.setCoeff(1);
						break;
					case SymbolTypes::minus:
						engine.setCoeff(-1);
						break;
					case SymbolTypes::digit:
						engine.setCoeff();
						break;
					}
					break;
				case SymbolTypes::trail:
					engine.addMonomial(AddMode::puth_others);
					engine.to(4);
					break;
				default: engine.go_wrong("некорректно введен коэффициент");
				}
				break;
			case 2:
				switch (type)
				{
				case SymbolTypes::digit:
					engine.read(); break;
				case SymbolTypes::sign:
					engine.addGrade(AddMode::push_empty);
					engine.addMonomial(AddMode::push_empty);
					engine.to(1); break;
				case SymbolTypes::letter:
					engine.addGrade(AddMode::push_empty);
					engine.to(2); break;
				case SymbolTypes::trail:
					engine.addGrade(AddMode::push_empty);
					engine.addMonomial(AddMode::push_empty);
					engine.to(4); break;
				case SymbolTypes::cap:
					engine.setBase();
					engine.to(3); break;
				default: engine.go_wrong("некорректно введен коэффициент");
				}
				break;
			case 3:
				switch (type)
				{
				case SymbolTypes::digit:
					engine.to(5); break;
				default: engine.go_wrong("некорректно введен коэффициент");
				}
				break;
			case 5:

				switch (type)
				{
				case SymbolTypes::digit:
					engine.read(); break;
				case SymbolTypes::sign:
					engine.addGrade(AddMode::puth_others);
					engine.addMonomial(AddMode::push_empty);
					engine.to(1); break;
				case SymbolTypes::letter:
					engine.addGrade(AddMode::puth_others);
					engine.to(2); break;
				case SymbolTypes::trail:
					engine.addGrade(AddMode::puth_others);
					engine.addMonomial(AddMode::push_empty);
					engine.to(4); break;
				default: engine.go_wrong("некорректно введен коэффициент");
				}
				break;

			case 6:
				switch (type) {
				case SymbolTypes::close_comment:
					engine.unpause();break;

				}
				break;
			}

		} while (!engine.stop());
		Polynomial p = engine.createPolynomial();
		input.addPolynomial(&p);
		input.setVariablesDictionary(engine.getDictionary());

	}

	// throws ParsingException if variableValue is out of range
	pair<string, double> Parser::inputVariableValue(const IArithmetic* rules, string source)
	{
		size_t place = source.find('=');
		string var_name = trim_copy(source.substr(0, place));
		string str_val = trim_copy(source.substr(place + 1));
		double var_val = stod(str_val);

		if (rules->belongs(var_val))
		{
			pair<string, double> res(var_name, var_val);
			return res;
		}
		throw ParsingException("При парсинге значений переменных встречено значение, не принадлежащее заданному множеству", place + 1);
	}



}