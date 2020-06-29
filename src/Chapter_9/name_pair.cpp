#include <name_pairs.hpp>

int main(int argc, char **argv) {
	NamePairs pair;
	pair.read_names();
	pair.read_ages();
	pair.print();
	pair.sort();
	pair.print();
}