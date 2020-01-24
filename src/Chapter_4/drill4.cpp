#include <limits>
#include <map>
#include <set>
#include <std_lib_facilities.hpp>

void two_values() {
	std::cout << "Please enter two integers" << '\n';
	int32_t value1{0}, value2{0};
	while (std::cin >> value1 >> value2) {
		std::cout << "First value = " << value1 << " Second value = " << value2 << '\n';
	}
	std::cout << std::endl;
}

void smaller() {
	std::cout << "Please enter two numbers" << '\n';
	int32_t first{0}, second{0};
	while (std::cin >> first >> second) {
		auto larger = (first > second) ? first : second;
		auto smaller = (first < second) ? first : second;
		std::cout << "The larger value is: " << larger << " The smaller value is: " << smaller << '\n';
	}
	std::cout << std::endl;
}

void equals() {
	std::cout << "Please enter two numbers or press '|' to exit" << '\n';
	int32_t first{0}, second{0};
	while (std::cin >> first >> second) {
		auto larger = (first > second) ? first : second;
		auto smaller = (first < second) ? first : second;
		if (first == second)
			std::cout << "The numbers " << first << " and " << second << " are equal" << '\n';
		else
			std::cout << "The larger value is: " << larger << " The smaller value is: " << smaller << '\n';
	}
	std::cout << std::endl;
}

void equals_double() {
	std::cout << "Please enter two numbers or press '|' to exit" << '\n';
	double first{0.0}, second{0.0};
	while (std::cin >> first >> second) {
		auto larger = (first > second) ? first : second;
		auto smaller = (first < second) ? first : second;
		if (first == second)
			std::cout << "The numbers " << first << " and " << second << " are equal" << '\n';
		else
			std::cout << "The larger value is: " << larger << " The smaller value is: " << smaller << '\n';
	}
	std::cout << std::endl;
}

void almost_equals() {
	std::cout << "Please enter two numbers or press '|' to exit" << '\n';
	double first{0.0}, second{0.0};
	while (std::cin >> first >> second) {
		auto larger = (first > second) ? first : second;
		auto smaller = (first < second) ? first : second;
		auto difference = larger - smaller;
		constexpr const double threshold = 1.0 / 100;
		if (first == second)
			std::cout << "The numbers " << first << " and " << second << " are equals" << '\n';
		else if (difference < threshold)
			std::cout << "the numbers " << larger << " and " << smaller << " are almost equals" << '\n';
		else
			std::cout << "The larger value is: " << larger << " The smaller value is: " << smaller << '\n';
	}
	std::cout << std::endl;
}

void one_double() {
	std::cout << "Please enter one number or '|' to exit" << '\n';
	double value{0.0};
	double min = std::numeric_limits<double>::max();
	double max = std::numeric_limits<double>::min();
	while (std::cin >> value) {
		std::cout << "Value entered = " << value;

		if (value < min) {
			min = value;
			std::cout << " is the smallest so far" << '\n';
		} else if (value > max) {
			max = value;
			std::cout << " is the biggest so far" << '\n';
		} else {
			std::cout << " is in between the min = " << min << " and the max = " << max << '\n';
		}
		std::cout << std::endl;
	}
}

void double_with_unit() {
	std::cout << "Please enter a number and its unit or '|' to exit" << '\n';
	double value{0.0};
	String unit{"\0"};
	constexpr const auto m_to_cm = 100l;
	constexpr const auto in_to_cm = 2.54l;
	constexpr const auto ft_to_in = 12l;
	std::map<String, size_t> units{{"cm", 0}, {"m", 1}, {"in", 2}, {"ft", 3}};
	while (std::cin >> value >> unit) {
		auto search = units.find(unit);
		if (search == units.end()) {
			simple_error("Unit (" + unit + ") not supported");
		}
		double in_meters{0.0}, in_centimeters{0.0}, in_inches{0.0}, in_feets{0.0};
		switch (search->second) {
		case 0:
			in_meters = value / m_to_cm;
			in_inches = value / in_to_cm;
			in_feets = in_inches / ft_to_in;
			std::cout << value << unit << " is " << in_meters << " m, " << in_inches << " in, " << in_feets << " ft"
			          << '\n';
			break;
		case 1:
			in_centimeters = value * m_to_cm;
			in_inches = in_centimeters / in_to_cm;
			in_feets = in_inches / ft_to_in;
			std::cout << value << unit << " is " << in_centimeters << " cm, " << in_inches << " in, " << in_feets
			          << " ft" << '\n';
			break;
		case 2:
			in_centimeters = value * in_to_cm;
			in_meters = in_centimeters / m_to_cm;
			in_feets = value / ft_to_in;
			std::cout << value << unit << " is " << in_meters << " m, " << in_centimeters << " cm, " << in_feets
			          << " ft" << '\n';
			break;
		case 3:
			in_inches = value * ft_to_in;
			in_centimeters = in_inches * in_to_cm;
			in_meters = in_centimeters / m_to_cm;
			std::cout << value << unit << " is " << in_meters << " m, " << in_centimeters << " cm, " << in_inches
			          << " in" << '\n';
			break;
		default:
			simple_error("Wrong option");
			break;
		}
	}
	std::cout << "Finishing program or exiting program due to wrong input. (Correct input must be 12 cm)" << std::endl;
}

void keep_sum() {
	std::cout << "Please enter a number and its unit or '|' to exit" << '\n';
	double value{0.0};
	String unit{"\0"};
	constexpr const auto m_to_cm = 100l;
	constexpr const auto in_to_cm = 2.54l;
	constexpr const auto ft_to_in = 12l;
	std::map<String, size_t> units{{"cm", 0}, {"m", 1}, {"in", 2}, {"ft", 3}};
	auto largest = std::numeric_limits<double>::min();
	auto smallest = std::numeric_limits<double>::max();
	double sum_in_meters{0.0};
	size_t count_values{0};
	Vector<double> values_in_meters;
	while (std::cin >> value >> unit) {
		auto search = units.find(unit);
		if (search == units.end()) {
			simple_error("Unit (" + unit + ") not supported");
		}
		double in_meters{0.0}, in_centimeters{0.0}, in_inches{0.0}, in_feets{0.0};
		switch (search->second) {
		case 0:
			in_meters = value / m_to_cm;
			in_inches = value / in_to_cm;
			in_feets = in_inches / ft_to_in;
			std::cout << value << unit << " is " << in_meters << " m, " << in_inches << " in, " << in_feets << " ft"
			          << '\n';
			break;
		case 1:
			in_meters = value;
			in_centimeters = in_meters * m_to_cm;
			in_inches = in_centimeters / in_to_cm;
			in_feets = in_inches / ft_to_in;
			std::cout << in_meters << " " << unit << " is " << in_centimeters << " cm, " << in_inches << " in, "
			          << in_feets << " ft" << '\n';
			break;
		case 2:
			in_inches = value;
			in_centimeters = in_inches * in_to_cm;
			in_meters = in_centimeters / m_to_cm;
			in_feets = in_inches / ft_to_in;
			std::cout << in_inches << " " << unit << " is " << in_meters << " m, " << in_centimeters << " cm, "
			          << in_feets << " ft" << '\n';
			break;
		case 3:
			in_feets = value;
			in_inches = in_feets * ft_to_in;
			in_centimeters = in_inches * in_to_cm;
			in_meters = in_centimeters / m_to_cm;
			std::cout << in_feets << " " << unit << " is " << in_meters << " m, " << in_centimeters << " cm, "
			          << in_inches << " in" << '\n';
			break;
		default:
			simple_error("Wrong option");
			break;
		}
		smallest = (in_meters < smallest) ? in_meters : smallest;
		largest = (in_meters > largest) ? in_meters : largest;
		sum_in_meters += in_meters;
		count_values++;
		values_in_meters.push_back(in_meters);
	}
	std::cout << "The smallest is " << smallest << "m - the largest is " << largest << "m - the number of values is "
	          << count_values << " - the total sum in meters is " << sum_in_meters << '\n';
	std::sort(values_in_meters.begin(), values_in_meters.end());
	for (auto &value : values_in_meters) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	// two_values();
	// smaller();
	// equals();
	// equals_double();
	// almost_equals();
	// one_double();
	// double_with_unit();
	keep_sum();
}