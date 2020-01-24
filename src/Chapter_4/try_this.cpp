#include "std_lib_facilities.hpp"

#include <algorithm>

void char_table() {
	constexpr const auto last_char = static_cast<int32_t>('z' - 'a');
	for (size_t i = 0; i <= last_char; ++i) {
		std::cout << char('a' + i) << '\t' << int('a' + i) << '\n';
	}
	std::cout << std::endl;
}

void char_table_complete() {
	constexpr const auto last_char = 126;
	for (size_t i = 33; i <= last_char; ++i) {
		std::cout << char(i) << '\t' << int(i) << '\n';
	}
	std::cout << std::endl;
}

void square() {
	std::cout << "Please enter a value to calculate the square" << '\n';
	size_t value{0};
	std::cin >> value;
	size_t result{0};
	for (size_t i = 0; i != value; ++i) {
		result += value;
	}
	std::cout << "Square of " << value << " is " << result << std::endl;
}

void bleep() {
	Vector<String> disliked_words;
	disliked_words.push_back("diego");
	bool disliked = false;
	for (string word; std::cin >> word;) {
		for (auto &disliked_word : disliked_words) {
			if (word == disliked_word) {
				std::cout << " BLEEP ";
				disliked = true;
				break;
			}
		}
		if (!disliked) {
			std::cout << " " << word << " ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

void dictionary() {
	Vector<String> words;
	for (String word; std::cin >> word;) {
		words.push_back(word);
	}
	std::cout << "Number of words " << words.size() << '\n';
	std::sort(words.begin(), words.end());
	for (size_t i = 0; i != words.size(); ++i) {
		if (i == 0 || words[i - 1] != words[i]) {
			std::cout << words[i] << '\n';
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	// char_table();
	// char_table_complete();
	// square();
	// bleep();
	dictionary();
}