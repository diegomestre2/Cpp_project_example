#include <calculator.hpp>
#include <memory>
int main() {
	auto calculator = std::make_unique<Calculator>();
	calculator->run();
}
//------------------------------------------------------------------------------
