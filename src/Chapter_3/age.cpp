#include <iostream>
#include <string>

/*int main (int argc, char** argv) {
    std::cout << " Please enter your first and second name" << '\n';
    std::string first{""};
    std::string second{""};
    std::cin >> first >> second;
    std::cout << "Hello, " << first << " " << second << '\n';

    std::cout << "Please enter your age" << '\n';
    double age{0.0};
    std::cin >> age;
    age *= 12;
    std::cout << "You are " << age << " months old" << '\n';
}*/

int main(int argc, char **argv) {
	std::cout << "Please enter your first and second name" << '\n';
	std::string first{""};
	std::string second{""};
	std::cin >> first >> second;
	std::string full_name = first + " " + second;
	std::cout << "your full name is " << full_name << std::endl;
}