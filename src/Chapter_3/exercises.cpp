#include "std_lib_facilities.hpp"

void miles_to_km() {
	std::cout << "Please enter the number of miles:" << '\n';
	double miles{0.0};
	std::cin >> miles;
	constexpr const double miles_in_km = 1.609;
	auto kilometers = miles * miles_in_km;
	std::cout << miles << " miles corresponds to " << kilometers << " kilometers" << std::endl;
}

void wrong_variable_names() {
	double a = 0;
	int b{0};
	char c{static_cast<char>(2.2)};
	double d = 0;
	std::cout << a << b << c << d << std::endl;
}

void two_integers() {
	std::cout << "Please enter two integers:" << '\n';
	int val1{0}, val2{0};
	std::cin >> val1 >> val2;
	std::cout << "Smaller = " << ((val1 < val2) ? val1 : val2) << '\n'
	          << "Larger = " << ((val1 > val2) ? val1 : val2) << '\n'
	          << "Sum = " << (val1 + val2) << '\n'
	          << "Difference = " << (val1 - val2) << '\n'
	          << "Product = " << (val1 * val2) << '\n'
	          << "Ratio = " << (double)(val1 / val2) << '\n'
	          << std::endl;
}

void two_floats() {
	std::cout << "Please enter two floats:" << '\n';
	double val1{0}, val2{0};
	std::cin >> val1 >> val2;
	std::cout << "Smaller = " << ((val1 < val2) ? val1 : val2) << '\n'
	          << "Larger = " << ((val1 > val2) ? val1 : val2) << '\n'
	          << "Sum = " << (val1 + val2) << '\n'
	          << "Difference = " << (val1 - val2) << '\n'
	          << "Product = " << (val1 * val2) << '\n'
	          << "Ratio = " << (double)(val1 / val2) << '\n'
	          << std::endl;
}

void order_three_integers() {
	std::cout << "Please enter three integers" << '\n';
	int one{0}, two{0}, three{0};
	std::cin >> one >> two >> three;
	if (two < one) {
		std::swap(one, two);
	}
	if (three < one) {
		std::swap(one, three);
	}
	if (three < two) {
		std::swap(two, three);
	}
	std::cout << one << " " << two << " " << three << std::endl;
}

void order_three_strings() {
	std::cout << "Please enter three strings" << '\n';
	String one{""}, two{""}, three{""};
	std::cin >> one >> two >> three;
	if (two < one) {
		std::swap(one, two);
	}
	if (three < one) {
		std::swap(one, three);
	}
	if (three < two) {
		std::swap(two, three);
	}
	std::cout << one << " " << two << " " << three << std::endl;
}

void odd_even() {
	std::cout << "Please enter an integer number" << '\n';
	int value{0};
	std::cin >> value;
	if ((value % 2) == 0) {
		std::cout << "The value " << value << " is even" << '\n';
	} else {
		std::cout << "The value " << value << " is odd" << '\n';
	}
	std::cout << std::endl;
}

void spelled_out_number() {
	std::cout << "Please enter a spelled-out number" << '\n';
	String string{""};
	std::cin >> string;
	int number{0};
	if (string == "one") {
		number = 1;
	} else if (string == "two") {
		number = 2;
	} else if (string == "three") {
		number = 3;
	} else if (string == "four") {
		number = 4;
	} else {
		simple_error("not a number that I know");
	}
	std::cout << "Your number is " << number << std::endl;
}

void operation() {
	std::cout << "Please enter an operation and two operands" << '\n';
	double operandA{0.0}, operandB{0.0}, result{0.0};
	char operation{'\0'};
	std::cin >> operation >> operandA >> operandB;
	if (operation == '+') {
		result = operandA + operandB;
	} else if (operation == '-') {
		result = operandA - operandB;
	} else if (operation == '*') {
		result = operandA * operandB;
	} else if (operation == '/') {
		result = operandA / operandB;
	} else {
		simple_error("Operation not supported");
	}
	std::cout << "The result of the operation " << operation << " over the operands " << operandA << " and " << operandB
	          << " is " << result << std::endl;
}

void coins_count() {
	std::cout << "Please enter the number of pennies, nickles, dimes, quarters, hald-dolar and one dollar" << '\n';
	double pennies{0.0}, nickles{0.0}, dimes{0.0}, quarters{0.0}, half_dolar{0.0}, dolar{0.0};
	std::cin >> pennies >> nickles >> dimes >> quarters >> half_dolar >> dolar;
	String default_str = "You have ";
	auto total_value =
	    (dolar * 100) + (50 * half_dolar) + (25 * quarters) + (10 * dimes) + (5 * nickles) + (1 * pennies);
	std::cout << default_str << pennies << " pennies" << '\n'
	          << default_str << nickles << " nickles" << '\n'
	          << default_str << dimes << " dimes" << '\n'
	          << default_str << quarters << " quarters" << '\n'
	          << default_str << half_dolar << " half dolar" << '\n'
	          << default_str << dolar << " dolar" << '\n'
	          << "The value of all your coins is: " << total_value << " cents" << std::endl;
}

int main(int argc, char **argv) {
	// miles_to_km();
	// wrong_varaible_names();
	// two_integers();
	// two_floats();
	// order_three_integers();
	// order_three_strings();
	// odd_even();
	// spelled_out_number();
	// operation();
	coins_count();
}