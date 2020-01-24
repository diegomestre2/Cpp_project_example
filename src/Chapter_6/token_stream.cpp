#include "token_stream.hpp"

#include "std_lib_facilities.hpp"

Token TokenStream::get() {
	if (buffer_full) {
		buffer_full = false;
		return buffer;
	}
	char c;
	std::cin >> c; // note that >> skips white space, new line, tab etc.
	switch (c) {
	case quit:
	case print:
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '{':
	case '}':
	case '!':
		return Token(c);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': {
		std::cin.putback(c);
		double value{0.0};
		std::cin >> value;
		return Token(number, value);
	}
	default:
		error("Parser Exception: Bad Token!");
	}
	throw string("Bad Input");
}

void TokenStream::putback(Token token) {
	if (buffer_full) {
		error("Token Stream Exception: Trying to add a token to a full buffer");
	}
	buffer = token;
	buffer_full = true;
}