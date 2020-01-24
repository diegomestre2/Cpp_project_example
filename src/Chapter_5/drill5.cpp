
#include "std_lib_facilities.hpp"

int main(int argc, char **argv) {
	try {
		std::cout << "Success!\n";
		std::cout << "Success!\n";
		std::cout << "Success!\n";
		std::cout << "Success!\n";
		string res = "7";
		vector<string> v(10);
		v[5] = res;
		std::cout << "Success!" << '\n';
		bool cond = true;
		if (cond) {
			std::cout << "Success!" << '\n';
		} else {
			std::cout << "Fail!" << '\n';
		}
		bool c = false;
		if (!c) {
			std::cout << "Success!" << '\n';
		} else {
			std::cout << "Fail!" << '\n';
		}
		string s = "ape";
		c = ("fool" == s);
		if (c) {
			std::cout << "Success!" << '\n';
		}
		s = "ape";
		if (s == "fool") {
			std::cout << "Success!" << '\n';
		}
		s = "ape";
		if (s == "fool") {
			std::cout << "Success!" << '\n';
		}
		s = "ape";
		if (s == "fool") {
			std::cout << "Success!" << '\n';
		}
		keep_window_open();
		return 0;
	} catch (exception &e) {
		std::cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	} catch (...) {
		std::cerr << "oops: unknown exception!" << '\n';
		keep_window_open();
		return 2;
	}
}