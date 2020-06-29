#include "namespace.hpp"

int main(int argc, char **argv) {

	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::print;
		using Z::var;
		var = 11;
		print();
	}
	print();
	X::print();
}