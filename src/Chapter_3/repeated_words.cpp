#include <iostream>
#include <string>

// int main(int argc, char** argv) {
// 	std::cout << "Please enter with a sentence to count repeated words" << '\n';
// 	std::string previous{" "};
// 	std::string current{" "};
//     while(std::cin >> current) {
//         if(current == previous) {
// 			std::cout << "repeated word= " << current << '\n';
// 		}
// 		previous = current;
// 	}
// }

int main(int argc, char** argv) {
	std::cout << "Please enter a sentence to count repeated words" << '\n';
	std::string previous{" "};
	std::string current{" "};
	size_t number_of_words{0};
	while (std::cin >> current) {
			++number_of_words;
		if (current == previous) {
			std::cout << "word number=" << number_of_words << " repeated:" << current << '\n';
		}
		previous = current;
	}
}