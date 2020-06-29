#include "my.hpp"

#include <iostream>

int main(int argc, char **argv) {
	print_foo();
	print(99);
	int x = 7;
	int y = 9;
	swap_r(x, y);
	std::cout << x << " " << y << '\n';
	// swap_v(7, 9); expects l-value
	const int cx = 7;
	const int cy = 9;
	// swap_cr(cx, cy); loses const
	std::cout << cx << " " << cy << '\n';
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	std::cout << dx << " " << dy << '\n';
	swap_v(7.7, 9.9);
}