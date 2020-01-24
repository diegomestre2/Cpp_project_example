#include "game.hpp"

Game::Game(const Game &rhs) : playing(rhs.playing), solution(rhs.solution) {
}

Game::Game(Game &&rhs) noexcept : playing(rhs.playing), solution(rhs.solution) {
	rhs.solution = "";
}

Game &Game::operator=(const Game &rhs) {
	auto temp = rhs;
	std::swap(*this, temp);
	return *this;
}

Game &Game::operator=(Game &&rhs) noexcept {
	if (this == &rhs)
		return *this;
	solution = std::move(rhs.solution);
	playing = rhs.playing;
	return *this;
}
void Game::init(uint32_t seed) {
	bulls = 0;
	cows = 0;
	playing = true;
	solution = generate_solution(seed);
}

uint16_t Game::factorial_seed() {
	auto step = first + second;
	if (step == 1)
		return 1;
	first = second;
	second = step;
	return step;
}

string Game::generate_solution(uint32_t seed) {
	string solution{""};
	auto rand_number = std::rand() % seed;
	// generate random factorial
	for (size_t i = 0; i != rand_number; i++) {
		factorial_seed();
	}
	// solution is the sequence of 4 characters from [a-z]
	for (size_t i = 0; i != 4; ++i) {
		solution += static_cast<char>(min_char + (factorial_seed() % ((max_char + 1) - min_char)));
	}
	return solution;
}

void Game::verify_answer(string &guess) {
	for (size_t i = 0; i != 4; ++i) {
		for (size_t j = 0; j != 4; j++) {
			if (guess[i] == solution[j]) {
				if (i == j) {
					cows++;
				} else {
					bulls++;
				}
			}
		}
	}
}

void Game::reset() {
	cows = bulls = 0;
}