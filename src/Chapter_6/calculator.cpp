#include "calculator.hpp"

void Calculator::putback_token(Token token) {
	ts.putback(token);
}

Token Calculator::get_token() {
	return ts.get();
}

double Calculator::evaluate_expression() {
	double left_term = next_term(); // read and evaluate a term
	Token token = ts.get();         // get the next token
	while (true) {
		switch (token.kind) {
		case '+':
			left_term += next_term(); // evaluate term and add
			token = ts.get();
			break;

		case '-':
			left_term -= next_term(); // evaluate term and subtract
			token = ts.get();
			break;

		default:
			ts.putback(token);
			return left_term; // finally, no more operators to evaluate, so return the answer
		}
	}
}

double Calculator::next_term() {
	double left_primary = next_primary();
	Token token = ts.get();
	while (true) {
		switch (token.kind) {
		case '*':
			left_primary *= next_primary();
			token = ts.get();
			break;
		case '/': { // The block is enforced by the compiler when initiallizing a variable inside a switch statement
			auto divisor = next_primary();
			if (divisor == 0) {
				error("Exception Parser Term: Division by 0 is not allowed");
			}
			left_primary /= divisor;
			token = ts.get();
			break;
		}
		default:
			ts.putback(token);
			return left_primary;
		}
	}
}

double Calculator::next_primary() {
	Token token = ts.get();
	switch (token.kind) {
	case '{': {
		auto expr = evaluate_expression();
		token = ts.get();
		if (token.kind != '}') {
			error("Exception Parser Primary: Expected '}'");
		}
		return expr;
	}
	// handle (expression)
	case '(': {
		auto expr = evaluate_expression();
		token = ts.get();
		if (token.kind != ')') {
			error("Exception Parser Primary: Expected ')'");
		}
		return expr;
	}
	case number: {
		auto value = next_value(token.value);
		return value;
	}
	case quit:
		ts.putback(token);
		return 0;
	default:
		error("Exception Parser Primary: Expected a primary value");
	}
	throw string("Bad Token kind");
}

int Calculator::next_value(int left_primary) {
	Token token = ts.get();
	switch (token.kind) {
	case '!':
		return factorial(left_primary);
	default:
		ts.putback(token);
		return left_primary;
	}
	return 0;
}

int Calculator::factorial(int number) {
	if (number == 0 || number == 1) {
		return 1;
	}
	return number * factorial(number - 1);
}