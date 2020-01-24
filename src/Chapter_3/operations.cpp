#include <iostream>
#include <cmath>


/*int main(int argc, char** argv) {
	std::cout << "Please enter a float-point value" << '\n';
	float n{0.0};
	std::cin >> n;
    std::cout << "n == "                  << n
              << "\nn+1 == "              << n+1
              << "\nthree times n == "    << 3*n
              << "\ntwice n == "          << n+n
              << "\nn squared == "        << n*n
              << "\nhalf of n == "        << n/2
              << "\nsquare root of n == " << sqrt(n)
              << '\n';
}*/

int main(int argc, char** argv) {
	std::cout << "Please enter an integer value" << '\n';
	int n{0};
	std::cin >> n;
    std::cout << "n == "                  << n
              << "\nn+1 == "              << n+1
              << "\nthree times n == "    << 3*n
              << "\ntwice n == "          << n+n
              << "\nn squared == "        << n*n
              << "\nhalf of n == "        << n/2
              << "\nsquare root of n == " << sqrt(n)
              << "\nremainder of half of n == " << n%2
              << "\nright shift by two == " << (n>>2)
              << "\nleft shift by two == " << (n<<2)
              << '\n';
}