#pragma once
constexpr const char number = '8'; // indicates token.kind == number
constexpr const char quit = 'x';   // indicates token.kind == quit
constexpr const char print = '=';  // indicates token.kind == print

class Token {
public:
	Token() = default;
	Token(char kind) : kind(kind), value(0) {
	}
	Token(char kind, double value) : kind(kind), value(value) {
	}
	~Token() = default;

	char kind;
	double value;
};