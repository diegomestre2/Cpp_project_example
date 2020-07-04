#pragma once
#include "std_lib_facilities.hpp"

#include <algorithm>

constexpr const uint16_t min_char = 97;
constexpr const uint16_t max_char = 122;

class Game {
public:
	Game() = default;                     // Default constructor
	~Game() noexcept = default;           // Default destructor
	Game(const Game &rhs);                // Copy constructor
	Game &operator=(const Game &rhs);     // Copy assignment
	Game(Game &&rhs) noexcept;            // Move constructor
	Game &operator=(Game &&rhs) noexcept; // Move assingment

	void init(uint32_t seed);
	void verify_answer(string &guess);
	uint16_t factorial_seed();
	void reset();
	uint16_t bulls;
	uint16_t cows;

	bool playing;
	string solution;

private:
	string generate_solution(uint32_t seed);
	uint16_t first = 1;
	uint16_t second = 2;
};