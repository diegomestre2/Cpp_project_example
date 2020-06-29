#include "my.hpp"

#include "std_lib_facilities.hpp"
int foo = 7;

void print_foo() {
	cout << foo << endl;
}

void print(int i) {
	cout << i << endl;
}

void swap_v(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap_r(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap_cr(const int &a, const int &b) {
	int temp = a;
}