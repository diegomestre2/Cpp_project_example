#define CATCH_CONFIG_RUNNER
#include "catch2/catch_all.hpp"

#include <test_helpers.hpp>

int main(int argc, char *argv[]) {
	std::cout << "test" << std::endl;
	int result = Catch::Session().run(argc, argv);

	return result;
}