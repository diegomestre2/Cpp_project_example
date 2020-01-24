#include "std_lib_facilities.hpp"

constexpr const double yen_dolar = 0.0091;
constexpr const double euro_dolar = 1.12;
constexpr const double pound_dolar = 1.3;

int main(int argc, char **argv) {
	std::cout << "Please enter the coind specification (y=yen, e=euro,p=pounds) and the amount to convert" << '\n';
	char coin{'\0'};
	double amount{0};
	double result{0};
	String currency{"\0"};
	std::cin >> coin >> amount;

	switch (coin) {
	case 'y':
		result = amount * yen_dolar;
		currency = "yens";
		break;
	case 'p':
		result = amount * pound_dolar;
		currency = "pounds";
		break;
	case 'e':
		result = amount * euro_dolar;
		currency = "euros";
		break;
	default:
		simple_error("Currency not supported!");
	}
	std::cout << amount << " in " << currency << " converts to " << result << " in dolars" << std::endl;
}