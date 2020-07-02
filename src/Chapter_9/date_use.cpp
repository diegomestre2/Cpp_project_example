#include <chrono.hpp>

void test_date(int x, int y) {
	{
		using namespace Chrono;
		try {
			Date today(1978, Month::jun, 25); // colloquial style
			Date tomorrow = today;            // copy constructor
			tomorrow.add_day(1);
			std::cout << "Today: " << today << std::endl;
			std::cout << "Tomorrow: " << tomorrow << std::endl;
			Date invalid_date = Date(2004, Month::dec, -5); // verbose style
		} catch (Date::Invalid) {
		}
	}
}

int main(int argc, char **argv) {
	test_date(1, 2);
}