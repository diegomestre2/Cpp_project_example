#pragma once
#include <iostream>
class Point {
public:
	Point(int x_, int y_) : x(x_), y(y_) {
	}
	void print() {
		std::cout << x << "," << y << '\n';
	};
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}

private:
	int x;
	int y;
};

std::ostream &operator<<(std::ostream &os, Point point) {
	os << point.get_x() << point.get_y();
	return os;
}
