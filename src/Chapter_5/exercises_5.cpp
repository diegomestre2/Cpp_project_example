#include "std_lib_facilities.hpp"

#include <algorithm>
#include <unordered_set>

double ctok(double c) {
	try {
		if (c < -273.15) {
			throw string("Error Absolute zero is -273.15");
		}
	} catch (const string &error) {
		std::cerr << error << '\n';
		exit(1);
	}

	return c + 273.15;
}

void temperature2() {
	std::cout << "Please enter with the temperature:" << '\n';
	double c{0.0};
	std::cin >> c;
	double k = ctok(c);
	std::cout << k << std::endl;
}

void temperature() {
	double c = 0;
	std::cin >> c;
	try {
		if (c < -273.15) {
			throw string("Erro: Absolute zero is -273.15");
		}
	} catch (string error) {
		std::cout << error << '\n';
		exit(1);
	}
	double k = ctok(c);
	std::cout << k << '\n';
}

void converts() {
	std::cout << "Please enter the temperature in Kelvin:" << '\n';
	double t{0.0};
	std::cin >> t;
	std::cout << t - 273.15 << " " << std::endl;
}

void convert_fc() {
	std::cout << "Please enter the temperature in Celsius" << '\n';
	double temp{0.0};
	std::cin >> temp;
	double celsius = (9.0 / 5) * temp + 32;
	std::cout << celsius << " F" << '\n';
	std::cout << "Please enter the temperature in Fahrenheit:" << '\n';
	double f{0.0};
	std::cin >> f;
	double fahrenheit = (f - 32) / (9.0 / 5.0);
	std::cout << fahrenheit << " C" << '\n';
}

void calculate_roots(double &r1, double &r2, double a, double b, double c) {
	//
	try {
		auto delta = (b * b) - (4 * a * c);
		if (delta < 0) {
			throw string("complex number is not supported!");
		}
		r1 = (-b + delta) / (2 * a);
		r2 = (-b - delta) / (2 * a);

	} catch (string exception) {
		std::cout << exception << std::endl;
		exit(1);
	}
}

void quadratic_equation() {
	//
	std::cout << "Please enter the terms a,b,c from your quadratic equation:" << '\n';
	double a{0.0}, b{0.0}, c{0.0};
	std::cin >> a >> b >> c;
	double root1{0.0}, root2{0.0};
	calculate_roots(root1, root2, a, b, c);
	std::cout << " Roots: " << root1 << " " << root2 << std::endl;
}

void sum_n() {
	std::cout << "Please enter the number of values to sum:" << '\n';
	size_t n = 0;
	std::cin >> n;
	std::cout << "Please enter some integers (press '|' to stop):" << '\n';
	vector<int32_t> values;
	int32_t value;
	while (std::cin >> value) {
		values.push_back(value);
	}
	try {
		if (values.size() < n) {
			throw string("Exception: Number of provided integers is inferior to n");
		}
		size_t sum = 0;
		for (size_t i = 0; i != n; ++i) {
			sum += values[i];
		}
		std::cout << " Sum of the first " << n << " values is " << sum << std::endl;
	} catch (string exception) {
		std::cout << exception << std::endl;
		exit(1);
	}
}

int fibonacci(int n) {
	if (n < 2)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci(double n) {
	double prev = 1.0, current = 1.0;
	double term = 1.0;
	int i = 0;
	vector<double> differences;
	try {
		while (i <= n) {
			++i;
			std::cout << term << " ";
			term = prev + current;
			if (term < 0) {
				throw string("Exception : Overflow int!");
			}
			differences.push_back(term - current);
			prev = current;
			current = term;
		}
	} catch (string exception) {
		std::cout << exception << std::endl;
		exit(1);
	}
	std::cout << std::endl;
	for (auto &diff : differences) {
		std::cout << diff << " ";
	}
	std::cout << std::endl;
	return 0;
}

void fib() {
	std::cout << "Please enter the number of terms that should be printed as a Fibbonacci sequence" << '\n';
	double n{0};
	std::cin >> n;
	fibonacci(n);
}

void bulls_cows() {
	std::cout << "Please enter a number to set the random seed:" << '\n';
	int n{0};
	std::cin >> n;
	srand(n);
	vector<int> numbers;
	numbers.push_back(randint(10));
	numbers.push_back(randint(10));
	numbers.push_back(randint(10));
	numbers.push_back(randint(10));
	int guess{0};
	int module{0};
	bool playing = true;
	while (playing) {
		std::cout << "Please enter a guess of four numbers (between 0-9):" << '\n';
		std::cin >> guess;
		module = guess;
		vector<int> guessing;
		// first we get all the digits individually
		for (size_t i = 1000; i >= 1; i /= 10) {
			guessing.push_back(module / i);
			module = module % i;
		}
		int bulls{0}, cows{0};
		// now we go for each number and compare against the given ones
		for (size_t i = 0; i != numbers.size(); ++i) {
			for (size_t j = 0; j != numbers.size(); ++j) {
				// check if guessing number is in the list
				if (numbers[i] == guessing[j]) {
					// in case positions are correct we have a bull
					if (i == j) {
						bulls++;
					} else { // otherwise we have a cow
						cows++;
					}
				}
			}
		}
		std::cout << "You got " << bulls << " bulls and " << cows << " cows" << std::endl;
		if (bulls == 4) {
			playing = false;
		}
	}
	std::cout << "You won! The numbers are " << numbers[0] << numbers[1] << numbers[2] << numbers[3] << std::endl;
}

void weekdays() {
	std::cout << "Please enter the days of the week followed by its number:" << '\n';
	vector<int> days;
	vector<string> weekdays;
	string weekday{""};
	int day{0};
	int sum{0};
	while (std::cin >> weekday >> day) {
		try {
			if (day < 1 || day > 31) {
				throw string("Error: Illegal day.");
			}
			string weekday_copy = "FRIDAY";
			std::for_each(weekday_copy.begin(), weekday_copy.end(), [&](char &c) { c = ::toupper(c); });
			// std::cout << weekday << " " << weekday_copy << " " << day << '\n';

			if (!(strcmp(weekday_copy.c_str(), "MONDAY") == 0 || strcmp(weekday_copy.c_str(), "MON") == 0 ||
			      strcmp(weekday_copy.c_str(), "TUESDAY") == 0 || strcmp(weekday_copy.c_str(), "TUE") == 0 ||
			      strcmp(weekday_copy.c_str(), "WEDNESDAY") == 0 || strcmp(weekday_copy.c_str(), "WED") == 0 ||
			      strcmp(weekday_copy.c_str(), "THURSDAY") == 0 || strcmp(weekday_copy.c_str(), "THU") == 0 ||
			      strcmp(weekday_copy.c_str(), "FRIDAY") == 0 || strcmp(weekday_copy.c_str(), "FRI") == 0)) {
				throw string("Error: Illegal weekday.");
			}

		} catch (string error) {
			std::cerr << error << std::endl;
			exit(1);
		}
		weekdays.push_back(weekday);
		days.push_back(day);
		sum += day;
	}
	for (size_t i = 0; i != days.size(); ++i) {
		std::cout << weekdays[i] << " " << days[i] << '\n';
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	// temperature();
	// temperature2();
	// converts();
	// convert_fc();
	// quadratic_equation();
	// sum_n();
	// fib();
	// bulls_cows();
	weekdays();
}