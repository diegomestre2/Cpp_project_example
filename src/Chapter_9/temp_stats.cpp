#include <fstream>
#include <iostream>
#include <vector>

void temp_stats() {
	std::ifstream input("raw_temps.txt");
	int h{0};
	double temp{0.0};
	std::vector<double> temperatures;
	while (true) {
		if (input >> h >> temp)
			break;
		temperatures.push_back(temp);
	}
	auto count = temperatures.size();
	size_t mean{0}, median{0};
	for (auto temp : temperatures) {
		mean += temp;
	}
	mean /= count;
	median = temperatures[count / 2];
	std::cout << "Mean: " << mean << " Median: " << median << std::endl;
}