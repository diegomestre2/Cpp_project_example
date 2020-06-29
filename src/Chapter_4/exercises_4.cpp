#include "std_lib_facilities.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <unordered_map>

void median() {
	std::cout << "Please enter a list of numbers" << '\n';
	Vector<double> temps;
	for (double temp{0.0}; std::cin >> temp;) {
		temps.push_back(temp);
	}
	size_t median_pos{0};
	if (temps.size() % 2 == 0)
		median_pos = (temps.size() / 2) - 1;
	else
		median_pos = (temps.size() / 2);
	std::cout << "Median is " << temps[median_pos] << std::endl;
}

void distance_cities() {
	std::cout << "Please enter a list of numbers" << '\n';
	Vector<double> cities_distance;
	auto smallest = std::numeric_limits<double>::max();
	auto greatest = std::numeric_limits<double>::min();
	double sum_distances{0};
	double mean_distance{0.0};

	for (double distance{0.0}; std::cin >> distance;) {
		smallest = (distance < smallest) ? distance : smallest;
		greatest = (distance > greatest) ? distance : greatest;
		sum_distances += distance;
		cities_distance.push_back(distance);
	}
	mean_distance = (sum_distances / cities_distance.size());
	std::cout << "The smallest distance is " << smallest << '\n'
	          << "The greatest distance is " << greatest << '\n'
	          << "The sum of the distances is " << sum_distances << '\n'
	          << "The mean of the distances is " << mean_distance << std::endl;
}

void guessing_number() {
	std::cout << "Guess a number between 1 and 100 and press 0 when you ready or 1 to exit" << '\n';
	size_t input{0};
	std::cin >> input;
	if (input == 1) {
		exit(1);
	}
	bool guessing = true;
	size_t answer{0};
	size_t limit_down = 1;
	size_t limit_up = 100;
	size_t guess = floor((limit_up + limit_down) / 2);
	while (guessing) {
		std::cout << "Is your number less than " << guess << " (0 for Yes and 1 for No  ) "
		          << " down " << limit_down << " up " << limit_up << '\n';
		std::cin >> answer;

		if (answer == 0) { // yes
			               // answer < guess
			limit_up = guess - 1;

		} else { // no
			     // answer > guess
			limit_down = guess + 1;
		}
		guess = floor((limit_up + limit_down) / 2);
		if ((limit_down > limit_up)) {
			std::cout << "The number you are thinking is " << guess << '\n';
			guessing = false;
		}
	}
}

void calculator() {
	std::cout << "Please enter two numbers and an operand" << '\n';
	double val_1{0.0}, val_2{0.0};
	char operation{'\0'};
	std::cin >> val_1 >> val_2 >> operation;

	switch (operation) {
	case '+':
		std::cout << "The sum of " << val_1 << " and " << val_2 << " is " << double(val_1 + val_2) << '\n';
		break;
	case '-':
		std::cout << "The difference of " << val_1 << " and " << val_2 << " is " << double(val_1 - val_2) << '\n';
		break;
	case '*':
		std::cout << "The multiplication of " << val_1 << " and " << val_2 << " is " << double(val_1 * val_2) << '\n';
		break;
	case '/':
		std::cout << "The division of " << val_1 << " and " << val_2 << " is " << double(val_1 / val_2) << '\n';
		break;
	default:
		break;
	}
}

void spelled_out_number() {
	std::cout << "Please enter a number to get the spelled-out version" << '\n';
	int number{0};
	std::cin >> number;
	assert(number < 10 && number >= 0);
	Vector<String> numbers;
	std::array<String, 10> names = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (size_t i = 0; i != names.size(); ++i) {
		numbers.push_back(names[i]);
	}
	std::cout << "your number is " << numbers[number] << std::endl;
}

vector<String> numbers;

void initialize_numbers() {
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
}

int get_val() {
	const int not_a_value = numbers.size();
	int val = not_a_value;
	if (std::cin >> val)
		return val;
	std::cin.clear(); // it failed so we should clean the buffer
	String s{"\0"};
	std::cin >> s;
	for (size_t i = 0; i != numbers.size(); ++i) {
		if (numbers[i] == s)
			val = i;
	}
	if (val == not_a_value)
		error("Unexpected value");
	return val;
}

void mini_calculator() {
	initialize_numbers();
	std::cout << "Please enter two integers numbers (it can be the spelled-out version) separated by an operator. The "
	             "operand can be - + * /"
	          << '\n';
	while (true) {
		int val_1 = get_val();
		char op{'\0'};
		std::cin >> op;
		int val_2 = get_val();

		string operation{"\0"};
		double result{0.0};
		switch (op) {
		case '+':
			operation = " sum of ";
			result = val_1 + val_2;
			break;
		case '-':
			operation = " difference of ";
			result = val_1 - val_2;
			break;
		case '*':
			operation = " multiplication of ";
			result = val_1 * val_2;
			break;
		case '/':
			operation = " division of ";
			result = val_1 / val_2;
			break;
		default:
			error("Unexpected operand!");
		}
		std::cout << operation << val_1 << " and " << val_2 << " is " << result << '\n';
		std::cout << " Try again or press Ctrl + C to exit" << std::endl;
	}
}

void square_count() {

	int squares{0}, rice_count{0}, grains{0};
	std::cout << "Please enter the amount of grains" << '\n';
	int limit{0};
	std::cin >> limit;
	for (size_t i = 1; grains <= limit; i++) {
		rice_count = i * i;
		grains += rice_count;
		squares++;
	}
	std::cout << squares << std::endl;
}

void rice_count() {
	std::cout << "Please enter the number of squares as an integer" << '\n';
	int limit_int{0};
	std::cin >> limit_int;
	int rice_count{0}, squares{0}, grains{0};
	for (size_t i = 0; i <= limit_int; ++i) {
		rice_count = i * i;
		grains += rice_count;
		squares++;
	}
	std::cout << rice_count << std::endl;
	std::cout << "Please enter the number of squares as a double" << '\n';
	double limit{0};
	std::cin >> limit;
	double rice{0}, square{0}, grain{0};
	for (size_t i = 0; i <= limit; ++i) {
		rice = i * i;
		grain += rice_count;
		square++;
	}
	std::cout << rice << std::endl;
}

int first{1}, second(2);

int fibbonacci() {
	int step = first + second;
	if (step <= 0)
		return 1;
	first = second;
	second = step;
	return step;
}

void generate_player(int seed) {
	if (seed < 0)
		seed = -seed;
	seed = seed % 10;
	for (size_t i = 0; i != seed; ++i) {
		fibbonacci();
	}
}

int get_computer_move() {
	return fibbonacci() % 3;
}

void rock_paper_scissors() {
	std::cout << " Please enter a value to set my random player" << '\n';
	int seed{0};
	std::cin >> seed;
	generate_player(seed);
	int draws{0}, player1{0}, player2{0};
	while (true) {
		std::cout << "Enter your option to play: (rock, paper, scissors)" << '\n';
		string user_input{"\0"};
		std::cin >> user_input;
		int user_option{-1};
		vector<String> options;
		options.push_back("paper");
		options.push_back("rock");
		options.push_back("scissors");

		if (user_input == "paper" || user_input == "p") {
			user_input = "paper";
			user_option = 0;
		} else if (user_input == "rock" || user_input == "r") {
			user_input = "rock";
			user_option = 1;

		} else if (user_input == "scissors" || user_input == "s") {
			user_input = "scissors";
			user_option = 2;

		} else {
			error(" Unexpected input!");
		}

		int computer_option = get_computer_move();
		string computer_input = options[computer_option];
		string result{"\0"};
		if (user_option == computer_option) {
			result = " a draw!";
			++draws;
		} else if (user_option == 0 && computer_option == 1) {
			result = " you won!";
			player1++;
		} else if (user_option == 1 && computer_option == 2) {
			result = " you won!";
			player1++;
		} else if (user_option == 2 && computer_option == 0) {
			result = " you won!";
			player1++;
		} else {
			result = " I won!";
			player2++;
		}
		std::cout << '\n'
		          << "I choose " << computer_input << " and you choosed " << user_input << " so, " << result << '\n'
		          << '\n';
		std::cout << "Draws " << draws << '\n';
		std::cout << "User " << player1 << '\n';
		std::cout << "Computer " << player2 << '\n';
		std::cout << std::endl;
	}
}

bool is_prime(int32_t number) {
	for (size_t i = 2; i != number; ++i) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

void sieve_of_eratosthenis(vector<int32_t> &found_primes, const size_t max) {

	auto primes = unique_ptr<bool[]>(new bool[max]);
	memset(primes.get(), true, sizeof(primes));
	for (size_t p = 2; p <= max; ++p) {
		if (primes[p]) {
			found_primes.push_back(p);
			for (size_t i = p * p; i <= max; i += p) {
				primes[i] = false;
			}
		}
	}
}

void naive_prime(vector<int32_t> &found_primes, size_t max) {
	for (size_t i = 2; i <= max; ++i) {
		if (is_prime(i)) {
			found_primes.push_back(i);
		}
	}
}

bool recursive_prime(size_t n, size_t i) {
	if (i == 1 || n == 2) {
		return true;
	} else if ((n % i) == 0) {
		return false;
	}
	return recursive_prime(n, --i);
}

void find_primes() {
	while (true) {
		std::cout << "Please enter the max value to check primes:" << '\n';
		size_t max{0};
		std::cin >> max;
		assert(max > 1);

		vector<int32_t> found_primes;
		// naive_prime(found_primes, max);
		sieve_of_eratosthenis(found_primes, max);
		for (auto prime : found_primes) {
			std::cout << prime << " ";
		}
		std::cout << '\n' << "Try again..." << std::endl;
	}
}

void find_n_primes() {
	std::cout << "Please enter a number to get all primes until it:" << '\n';
	size_t n{0};
	std::cin >> n;
	for (size_t i = 2; i != n + 1; ++i)
		if (recursive_prime(i, i - 1))
			std::cout << i << " ";
	std::cout << std::endl;
}

void find_mode() {
	std::cout << "Please enter a sequence of numbers:" << '\n';
	int32_t number;
	vector<int32_t> numbers;
	while (std::cin >> number)
		numbers.push_back(number);
	size_t repetitions_cnt = std::numeric_limits<size_t>::min();
	size_t mode{0};
	// we go throw each value
	for (size_t i = 0; i != numbers.size(); ++i) {
		size_t current_repetitions{0};
		// and check against each of the other ones
		for (size_t j = numbers.size() - 1; j != i; --j) {
			// to count the repetitions
			if (numbers[i] == numbers[j]) {
				current_repetitions++;
			}
		}
		// in case the current number has more repetitions
		if (repetitions_cnt < current_repetitions) {
			// we store it as the new mode
			mode = numbers[i];
		}
	}
	std::cout << "This is the mode: " << mode << std::endl;
}
void min_max_mode_string() {
	std::cout << "Please enter a sequence of strings" << '\n';
	vector<string> words;
	string word{""}, mode{""};
	auto min = std::numeric_limits<size_t>::max();
	auto max = std::numeric_limits<size_t>::min();
	size_t current_cnt{0};
	string min_word{""}, max_word{""};
	while (std::cin >> word)
		words.push_back(word);
	for (size_t i = 0; i != words.size(); ++i) {
		size_t word_cnt{0};
		for (size_t j = words.size() - 1; j != i; --j) {
			if (words[i] == words[j])
				word_cnt++;
		}
		if (current_cnt < word_cnt)
			mode = words[i];
		if (words[i].size() < min) {
			min = words[i].size();
			min_word = words[i];
		}
		if (words[i].size() > max) {
			max = words[i].size();
			max_word = words[i];
		}
	}
	std::cout << " Min: " << min_word << '\n' << " Max: " << max_word << '\n' << " Mode: " << mode << std::endl;
}

void solve_quadratic_equation() {
	std::cout << "Please enter the values of a, b, c for the equation ax^2 + bx + c = 0" << '\n';
	double a{0}, b{0}, c{0};
	std::cin >> a >> b >> c;
	auto delta = sqrt((b * b) - (4 * a * c));
	auto x1 = ((-b + delta) / (2 * a));
	auto x2 = ((-b - delta) / (2 * a));
	std::cout << " The solution is x1= " << x1 << " and x2= " << x2 << std::endl;
}

void scores() {
	std::cout << "Please enter with names and scores as pairs (Enter NoName to finish)" << '\n';

	vector<string> names;
	vector<size_t> scores;
	string name{""};
	size_t score{0};
	while (true) {
		std::cin >> name >> score;
		if (name == "Noname")
			break;
		names.push_back(name);
		scores.push_back(score);
	}
	for (size_t i = 0; i != names.size(); ++i) {
		std::cout << " Name: " << names[i] << " Score: " << scores[i] << '\n';
	}
	std::cout << std::endl;
	std::cout << "Please enter a name to check the score:" << '\n';
	std::cin >> name;
	for (size_t j = 0; j != names.size(); ++j) {
		if (name == names[j]) {
			std::cout << " The score for " << name << " is " << scores[j] << '\n';
		}
	}
	std::cout << std::endl;
	std::cout << "Please enter a score to check the names who got it:" << '\n';
	std::cin >> score;
	for (size_t k = 0; k != scores.size(); ++k) {
		if (score == scores[k]) {
			std::cout << " Player: " << names[k] << " got the score: " << score << '\n';
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	// median();
	// distance_cities();
	// guessing_number();
	// calculator();
	// spelled_out_number();
	// mini_calculator();
	// square_count();
	// rice_count();
	// rock_paper_scissors();
	// find_primes();
	// find_n_primes();
	// find_mode();
	// min_max_mode_string();
	// solve_quadratic_equation();
	scores();
}