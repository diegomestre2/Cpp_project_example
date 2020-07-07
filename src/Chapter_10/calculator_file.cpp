#include "calculator.hpp"

#include <fstream>
#include <string>

void test_calculator_file() {
	auto input_file_name = string("input.txt");
	{
		std::ofstream output{input_file_name};
		output << "let x=2; x*3;";
	}
	{
		Calculator calculator;
		calculator.run();
	}
}