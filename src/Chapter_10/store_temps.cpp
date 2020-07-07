#include <fstream>
#include <iostream>
#include <random>

uint32_t get_random() {
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<uint32_t> distribution;
	return distribution(engine);
}

void test_store_temps() {
	auto file_name = std::string("raw_temps.txt");
	std::ofstream output(file_name);
	for (size_t i = 1; i != 51; ++i) {
		auto hour = static_cast<int>(get_random() % 24);
		auto temp = static_cast<double>((++hour + 50.5 / i));
		output << hour << " " << temp << '\n';
	}
}
