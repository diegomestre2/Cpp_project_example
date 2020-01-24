#include <iostream>


int main(int argc, char** argv) {
	std::cout << "Please enter a double value" << '\n';
	double d{0.0};

	while(std::cin >> d) {
		int i = d;
		char c = i;
		int i2 = c;
        std::cout << "d=="   << d
                  << "\ni=="   << i
                  << "\ni2=="  << i2
                  << "\nchar(" << c << ")\n";
	}
}