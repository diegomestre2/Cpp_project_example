#include <iostream>
#include "std_lib_facilities.hpp"

int main(int argc, char** argv) {
	std::cout << "Please enter the name of the person you want to write to, a friend's name, sex (m=male / f=female) and age" << '\n';
	String first_name{" "};
	String friend_name{" "};
	char friend_sex{'0'};
	int friend_age{0};
	std::cin >> first_name;
	std::cin >> friend_name;
	std::cin >> friend_sex;
	std::cin >> friend_age;
	std::cout << "Dear " << first_name << "," << '\n'
	          << "\nHow are you doing?" << '\n'
	          << "I hope you are doing good." << '\n'
	          << "Have you seen " << friend_name << "?" << '\n';
	if (friend_sex == 'm') {
		std::cout << "If you see " << friend_name << " please ask him to call me." << '\n';
	} else {
		std::cout << "If you see " << friend_name << " please ask her to call me." << '\n';
    }

    if (friend_age <= 0 || friend_age > 110) {
		simple_error("you're kidding!");
	}
    if (friend_age < 12) {
		std::cout << "Next year you will be " << friend_age + 1 << '\n';
	} else if (friend_age == 17) {
		std::cout << "Next year you will be able to vote." << '\n';
    } else if (friend_age > 70) {
		std::cout << "I hope you are enjoying retirement." << '\n';
    }
	std::cout << "Yours Sincerily," << '\n' << '\n' << "Diego Tomé." << std::endl;
}