#pragma once
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class NamePairs {
public:
	NamePairs() {
	}

	void read_names() {
		std::string name{"\0"};
		while (std::cin >> name) {
			names.push_back(name);
		}
	}
	void read_ages() {
		double age;
		for (auto &name : names) {
			std::cin >> age;
			ages.push_back(age);
		}
	}
	void print() {
		for (size_t i = 0; i != names.size(); ++i) {
			std::cout << names[i] << " " << ages[i] << '\n';
		}
		std::cout << std::endl;
	}
	void sort() {
		std::vector<size_t> positions(names.size());
		auto increment = [] {
			static int i = 0;
			return ++i;
		};
		std::generate(positions.begin(), positions.end(), increment);
		std::sort(names.begin(), names.end());
	}

private:
	std::vector<std::string> names{"\0"};
	std::vector<double> ages{0.0};
};