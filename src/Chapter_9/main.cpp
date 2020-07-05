#include "library.hpp"
#include "point.hpp"

#include <iostream>
#include <string>
#include <vector>

void test_library() {
	Library lib;
	auto book1 = Book("1-2-3-A", "one up", "Peter Lynch", "02-07-2020", Genre::nonfiction);
	auto book2 = Book("1-2-4-A", "learn to earn", "Peter Lynch", "02-07-2020", Genre::nonfiction);
	lib.add_book(book1);
	lib.add_book(book2);
	auto diego = std::string("diego");
	auto patron1 = Patron(diego, 123);
	auto jessica = std::string("jessica");
	auto patron2 = Patron(jessica, 124);
	lib.add_patron(patron1);
	lib.checkout_book(patron1, book1);
	lib.checkout_book(patron2, book2);
}

void test_point() {
	std::cout << "Give two coordinate members (x,y):" << '\n';
	std::vector<Point> original_points;

	{
		for (int x, y; std::cin >> x >> y;) {
			auto point = Point(x, y);
			original_points.push_back(point);
			point.print();
		}
	}
	std::cout << "Writing Points" << '\n';
	auto file_name = std::string("mydata.txt");
	{
		std::ofstream output{file_name};
		if (!output)
			std::cout << "error on output file!" << std::endl;
		for (auto &point : original_points) {
			output << point;
		}
	}
	std::cout << "Reading Points" << '\n';
	std::vector<Point> processed_points;
	{
		std::ifstream input{file_name};
		if (!input)
			std::cout << "error on input file!" << std::endl;
		char x, y;
		while (true) {
			if (!(input >> x >> y))
				break;
			processed_points.emplace_back(static_cast<int>(x - '0'), static_cast<int>(y - '0'));
		}
	}
	std::cout << "Processed" << '\n';
	for (auto &point : processed_points) {
		point.print();
	}
}

void test_sum_num() {
	auto file_name = std::string("sum.txt");
	{
		std::ofstream file(file_name);
		auto num_list = {1, 3, 5, 7, 9};
		for (auto num : num_list) {
			file << num << " ";
		}
	}
	std::ifstream file_in(file_name);
	char ch{'\0'};
	size_t sum{0};
	while (true) {
		if (!(file_in >> ch))
			break;
		if (ch == ' ')
			continue;
		sum += static_cast<int>(ch - '0');
	}
	std::cout << sum << std::endl;
}

int main(int argc, char **argv) {
	test_sum_num();
}