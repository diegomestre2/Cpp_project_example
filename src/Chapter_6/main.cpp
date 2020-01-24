// #include "calculator.hpp"
// #include "english_gramma.hpp"
// #include "name_value.hpp"
// #include "game.hpp"
//#include "std_lib_facilities.hpp"
#include <permutation.hpp>

/* int calculator() {
    std::cout << "** Welcome to our simple calculator with parser **" << '\n'
              << "** Please enter expressions using floating-point numbers ** " << '\n'
              << '\n'
              << "Supported operations (+, -, *, /)" << '\n'
              << "Supported precidence with '(' and ')'" << '\n'
              << "Supported options 'x'= quit and '=' to evaluate expressions ')'" << '\n'
              << '\n';
    try {
        Calculator calculator;
        double result{0.0};
        std::cout << "Expression: ";
        while (std::cin) {
            Token token = calculator.get_token();
            if (token.kind == quit) // exit
                break;
            if (token.kind == print) { // Finish expression and print result
                std::cout << "=" << result << '\n';
                std::cout << "Expression: ";
            } else {
                calculator.putback_token(token);
            }

            result = calculator.evaluate_expression();
        }
        keep_window_open();
    } catch (exception &e) {
        std::cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    } catch (...) {
        std::cerr << "exception \n";
        keep_window_open();
        return 2;
    }
}

void name_value() {
    std::cout << "Please enter a name and score pair" << std::endl;
    string name;
    double score;
    vector<NameValue> names;
    while (name != "NoName") {
        try {
            std::cin >> name >> score;
            for (size_t i = 0; i != names.size(); ++i) {
                if (names[i].name == name) {
                    throw string("Duplicate name");
                }
            }
        } catch (exception &e) {
            std::cerr << e.what() << std::endl;
        }
        NameValue pair(name, score);
        names.push_back(pair);
    }
    for (auto &pair : names) {
        std::cout << pair.name << " " << pair.value << std::endl;
    }
}

void english_gramma() {
    string sentence = "The birds fly but the fish swim.";
    EnglishEvaluator evaluator;
    bool result;
    evaluator.init();
    while (std::cin) {
        result = evaluator.evaluate_sentence();
    }
    if (result)
        std::cout << "Ok" << std::endl;
    else {
        std::cout << "Not Ok" << std::endl;
    }
}

void bulls_and_cows2() {
    Game game;
    std::cout << "Please enter a seed to generate the number:" << std::endl;
    uint32_t seed{0};
    std::cin >> seed;
    game.init(seed);

    while (game.playing) {
        std::cout << "Please enter four digits to guess:" << std::endl;
        string guess{""};
        std::cin >> guess;
        game.verify_answer(guess);
        if (game.cows == 4) {
            std::cout << "You won! "
                      << " Your guess was " << guess << " and the solution is " << game.solution << std::endl;
            game.playing = false;
        } else {
            std::cout << " You got " << game.bulls << " bulls and " << game.cows << " cows" << std::endl;
            game.reset();
        }
    }
}

void read_digits() {
    try {
        std::cout << "Please enter with a number of at most 4 digits:" << std::endl;
        vector<string> units;
        units.push_back("ones");
        units.push_back("tens");
        units.push_back("hundreds");
        units.push_back("thousands");
        units.push_back("tens of thousands");
        units.push_back("hundreds of thousands");
        units.push_back("millions");
        units.push_back("tens of millions");
        units.push_back("hundreds of millions");

        vector<int> digits;
        char digit{'\0'};
        while (std::cin >> digit) {
            if (digit < '0' || '9' < digit)
                break;
            digits.push_back(digit - '0');
        }
        if (digits.size() > units.size()) {
            error("Unit not supported");
        }
        if (digits.size() == 0)
            error("no input");
        // write out the number
        for (size_t i = 0; i != digits.size(); ++i) {
            std::cout << digits[i];
        }
        std::cout << " is ";
        for (size_t i = 0; i != digits.size(); ++i) {
            std::cout << digits[i] << " " << units[digits.size() - i - 1] << " ";
        }
        std::cout << std::endl;

    } catch (runtime_error e) {
        std::cout << e.what() << std::endl;
        keep_window_open("-");
    }
}*/

/*void permutation_combination() {
    std::cout << "Please enter two numbers one to represent the possibilities and other for the sequence:" << std::endl;
    int a, b;
    std::cin >> a >> b;
    char option{'\0./'};
    std::cout << "Press (c) to calculate the combination (p) for permutation and (b) for both" << std::endl;
    std::cin >> option;
    int result{0};
    if (option == 'c') {
        result = combination(a, b);
    } else if (option == 'p') {
        result = permutation(a, b);
    } else if (option == 'b') {
    } else {
        error("Invalid Option!");
        keep_window_open();
    }
}

int main(int argc, char **argv) {
    // calculator();
    // name_value();
    // english_gramma();
    // bulls_and_cows2();
    // read_digits();
    permutation_combination();
}*/